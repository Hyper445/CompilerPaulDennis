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

node* RFfundef(node* arg_node, info* arg_info) {
    DBUG_ENTER("RFfundef");    
    printf("fundef is being executed\n");
    int sum = 0;

    node *body = FUNDEF_FUNBODY(arg_node);
    node *stmts = FUNBODY_STMTS(body);
    
    FUNDEF_FUNBODY(arg_node) = TRAVopt(FUNDEF_FUNBODY(arg_node), arg_info);

    while(stmts != NULL) {
        node *current_stmt = STMTS_STMT(stmts);

        if (NODE_TYPE(current_stmt) == N_for) {
            // Create and a the new vardecl.
            node *start = COPYdoCopy(FOR_START(current_stmt));
            char *new_name = STRcat("for_",STRcat(FOR_LOOPVAR(current_stmt) , STRitoa(sum)));
            node *new_vardecl = TBmakeVardecl(T_int, new_name, NULL, NULL, start, FUNBODY_VARDECLS(body));
            sum = sum + 1;
            FUNBODY_VARDECLS(body) = new_vardecl;

            // Create the condition of the while loop.
            node *left = TBmakeVar(STRcpy(new_name), NULL, NULL);
            node *right = COPYdoCopy(FOR_STOP(current_stmt));
            node *condition = TBmakeBinop(BO_lt, left, right);

            // Create the block of the while loop.
            node *block = COPYdoCopy(FOR_BLOCK(current_stmt));

            // Create the while loop.
            node *new_while_loop = TBmakeWhile(condition, block);

            // Get the step expression.
            node *step_for = FOR_STEP(current_stmt);
            node *step_while;
            if (step_for == NULL) {
                node *step_varlet = TBmakeVarlet(STRcpy(new_name), NULL, NULL);
                node *step_expr_l = TBmakeVar(STRcpy(new_name), NULL, NULL);
                node *step_expr_r = TBmakeNum(1);
                node *step_expr = TBmakeBinop(BO_add, step_expr_l, step_expr_r);
                step_while = TBmakeAssign(step_varlet, step_expr);
            }
            else {
                node *step_while = COPYdoCopy(FOR_STEP(current_stmt));
            }
            node *current_block_stmts = FOR_BLOCK(current_stmt);
            while(current_block_stmts != NULL) {
                current_block_stmts = STMTS_NEXT(current_block_stmts);
            }
            node *step_stmts = TBmakeStmts(step_while, NULL);
            STMTS_NEXT(current_block_stmts) = step_stmts;

            // Free for loop.
            FREEdoFreeTree(current_stmt);

            


            // Replace the for loop.
            STMTS_STMT(stmts) = new_while_loop;
            
            
        }

        stmts = STMTS_NEXT(stmts);
    }


    

    DBUG_RETURN(arg_node);

}

/*
 * Traversal start function
 */

node *RFdoRestructureForLoop( node *syntaxtree)
{
    DBUG_ENTER("RFdoRestructureForLoop");

    TRAVpush( TR_rf);
    syntaxtree = TRAVdo( syntaxtree, NULL);
    TRAVpop();

    DBUG_RETURN( syntaxtree);
}