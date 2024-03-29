/*****************************************************************************
 *
 * Module: restructure forloop
 *
 * Prefix: RF
 *
 * Description:
 *
 * This module moves the declaration part of the for loop the the function the 
 * for-loop is part of. For example:
 * 
 * for (in i = 0, n) {statements}
 * 
 * This becomes:
 * 
 * int i = 0;
 * for (i, n) {statements}
 *****************************************************************************/


#include "code_generation.h"

#include "stdlib.h"
#include "lookup_table.h"
#include "types.h"
#include "tree_basic.h"
#include "traverse.h"
#include "dbug.h"
#include "str.h"
#include "copy.h"
#include "free.h"

#include "memory.h"
#include "ctinfo.h"

struct INFO {
  char* old_name;
  char* new_name;
};

#define INFO_OLDNAME(n) ((n)->old_name)
#define INFO_NEWNAME(n) ((n)->new_name)

static info *MakeInfo(void) {
  info *result;

  DBUG_ENTER( "MakeInfo");

  result = (info *)MEMmalloc(sizeof(info));
  INFO_OLDNAME(result) = NULL;
  INFO_NEWNAME(result) = NULL;
  DBUG_RETURN( result);
}

node* RFfundef(node* arg_node, info* arg_info) {
    DBUG_ENTER("RFfundef");    
    int sum = 0;

    node *body = FUNDEF_FUNBODY(arg_node);
    node* stmts = NULL;
    if (body) {
        stmts = FUNBODY_STMTS(body);
    }

    // Traverse through body of loop. In case of a for loop in an inner function, that for loop will be changed into a while loop first.
    FUNDEF_FUNBODY(arg_node) = TRAVopt(FUNDEF_FUNBODY(arg_node), arg_info);

    // Loops through all stmts nodes.
    while(stmts != NULL) {
        node *current_stmt = STMTS_STMT(stmts);

        if (NODE_TYPE(current_stmt) == N_for) {
            // Create and add the new vardecl.
            node *vardecl_expr = COPYdoCopy(FOR_START(current_stmt));
            char *vardecl_name = STRcat("for_",STRcat(FOR_LOOPVAR(current_stmt) , STRitoa(sum)));
            node *new_vardecl = TBmakeVardecl(T_int, vardecl_name, NULL, NULL, vardecl_expr, FUNBODY_VARDECLS(body));
            FUNBODY_VARDECLS(body) = new_vardecl;
            sum = sum + 1;

            // Change the vars in the body to the new name
            //FOR_LOOPVAR(current_stmt) = STRcpy(vardecl_name);

            INFO_OLDNAME(arg_info) = FOR_LOOPVAR(current_stmt);
            INFO_NEWNAME(arg_info) = vardecl_name;
            FOR_BLOCK(current_stmt) = TRAVopt(FOR_BLOCK(current_stmt), arg_info);

            // Create the condition of the while loop.
            node *left = TBmakeVar(STRcpy(vardecl_name), NULL, NULL);
            node *right = COPYdoCopy(FOR_STOP(current_stmt));
            node *condition;
            condition = TBmakeBinop(BO_lt, left, right);

            // Create the block of the while loop.
            node *block = COPYdoCopy(FOR_BLOCK(current_stmt));

            // Create the while loop.
            node *new_while_loop = TBmakeWhile(condition, block);

            // Create the step assign node.
            node *step_for = FOR_STEP(current_stmt);
            node *step_varlet = TBmakeVarlet(STRcpy(vardecl_name), NULL, NULL);
            node *step_expr_l = TBmakeVar(STRcpy(vardecl_name), NULL, NULL);
            node *step_expr_r;
            if (step_for == NULL) {
                step_expr_r = TBmakeNum(1);
            }
            else {
                step_expr_r = COPYdoCopy(FOR_STEP(current_stmt));
            }
            node *step_expr = TBmakeBinop(BO_add, step_expr_l, step_expr_r);
            node *step_while = TBmakeAssign(step_varlet, step_expr);

            // Add the step assign node at the end of the stmts of the body
            node *current_block_stmts = block;
            node *step_stmts = TBmakeStmts(step_while, NULL);
            if(block == NULL) {
                WHILE_BLOCK(new_while_loop) = step_stmts;
            }
            else {
                while(STMTS_NEXT(current_block_stmts) != NULL) {
                    current_block_stmts = STMTS_NEXT(current_block_stmts);
                }
                STMTS_NEXT(current_block_stmts) = step_stmts;
            }

            // Free for loop.
            FREEdoFreeTree(current_stmt);
            
            // Replace the for loop.
            STMTS_STMT(stmts) = new_while_loop;
            
            
        }

        stmts = STMTS_NEXT(stmts);
    }

    DBUG_RETURN(arg_node);

}

node* RFfor(node *arg_node, info* arg_info) {

    DBUG_ENTER("RFfor");

    FOR_BLOCK(arg_node) = TRAVopt(FOR_BLOCK(arg_node), arg_info);

    DBUG_RETURN(arg_node);

}

node *RFvarlet(node* arg_node, info* arg_info) {

    DBUG_ENTER("RFvar");

    if (STReq(VARLET_NAME(arg_node),INFO_OLDNAME(arg_info))) {

        VARLET_NAME(arg_node) = STRcpy(INFO_NEWNAME(arg_info));

    }

    DBUG_RETURN(arg_node);

}

node *RFvar(node* arg_node, info* arg_info) {

    DBUG_ENTER("RFvar");

    if (STReq(VAR_NAME(arg_node),INFO_OLDNAME(arg_info))) {

        VAR_NAME(arg_node) = STRcpy(INFO_NEWNAME(arg_info));

    }

    DBUG_RETURN(arg_node);

}

/*
 * Traversal start function
 */

node *RFdoRestructureForLoop( node *syntaxtree)
{
    info* arg_info;
    DBUG_ENTER("RFdoRestructureForLoop");

    arg_info = MakeInfo();

    TRAVpush( TR_rf);
    syntaxtree = TRAVdo( syntaxtree, arg_info);
    TRAVpop();

    DBUG_RETURN( syntaxtree);
}