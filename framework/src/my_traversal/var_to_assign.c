/*****************************************************************************
 *
 * Module: var_to_assign
 *
 * Prefix: VA
 *
 * Description:
 *
 * This module implements a demo traversal of the abstract syntax tree that 
 * sums up all integer constants and prints the result at the end of the traversal.
 *
 *****************************************************************************/


#include "var_to_assign.h"

#include "stdlib.h"
#include "lookup_table.h"
#include "types.h"
#include "tree_basic.h"
#include "traverse.h"
#include "dbug.h"
#include "str.h"

#include "memory.h"
#include "ctinfo.h"


/*
 * INFO structure
 */

struct INFO {
  int tempAmount;
};



/*
 * INFO macros
 */

#define INFO_TEMP(n) ((n)->tempAmount)


/*
 * INFO functions
 */


static info *MakeInfo(void)
{
  info *result;

  DBUG_ENTER( "MakeInfo");

  result = (info *)MEMmalloc(sizeof(info));

  INFO_TEMP(result) = 0;

  DBUG_RETURN( result);
}

void addNodeStatements(node* assign, node* funbody) {

  node* current_stmt = FUNBODY_STMTS(funbody);
  node* previous_stmt = NULL;

  if (NODE_TYPE(assign) != N_return) {
    while (current_stmt && NODE_TYPE(STMTS_STMT(current_stmt)) == N_assign && 
      STRsub("temp", VARLET_NAME(ASSIGN_LET(STMTS_STMT(current_stmt))))) {
        previous_stmt = current_stmt;
        current_stmt = STMTS_NEXT(current_stmt);
    }
  } else {
    while (current_stmt) {
      previous_stmt = current_stmt;
      current_stmt = STMTS_NEXT(current_stmt);  
    }   
  }

  if (previous_stmt) {
    STMTS_NEXT(previous_stmt) = TBmakeStmts(assign, current_stmt);

  } else {
    FUNBODY_STMTS(funbody) = TBmakeStmts(assign, current_stmt);
  }

}

void addNodeFundef(node* assign, node* program) {
    
    node* current_stmt = PROGRAM_DECLS(program);

    if (current_stmt) {
        while (DECLS_NEXT(current_stmt) != NULL) {
            current_stmt = DECLS_NEXT(current_stmt);
        }

        DECLS_NEXT(current_stmt) = TBmakeDecls(assign, NULL);
    } else {
        PROGRAM_DECLS(program) = TBmakeDecls(assign, NULL);
    }

}

/*
 * Traversal functions
 */

node *VAprogram( node* arg_node, info * arg_info) {

  DBUG_ENTER("VAprogram");

  node* funbody = TBmakeFunbody(NULL, NULL, NULL);
  node* fundef = NULL;
  node *current_decl = NULL;
  node *decls = PROGRAM_DECLS(arg_node);

  while (decls) {

    if (NODE_TYPE(DECLS_DECL(decls)) == N_globdef) { 
      current_decl = decls;
      break;
    }

    decls = DECLS_NEXT(decls);
  }

  while (current_decl) {
    if(NODE_TYPE(DECLS_DECL(current_decl)) == N_globdef && GLOBDEF_INIT(DECLS_DECL(current_decl))) {

        node* expression = GLOBDEF_INIT(DECLS_DECL(current_decl));
        char* temporaryName = STRcat(STRcpy("temp_"), STRitoa(INFO_TEMP(arg_info)));
        INFO_TEMP(arg_info)++;

        // Update current vardecl node to no initiation.
        GLOBDEF_NAME(DECLS_DECL(current_decl)) = STRcpy(temporaryName);
        GLOBDEF_INIT(DECLS_DECL(current_decl)) = NULL;

        //node* varlet = TBmakeVarlet(temporaryName, NULL, NULL);
        node* varlet = TBmakeVarlet(temporaryName, GLOBDEF_DECL(DECLS_DECL(current_decl)), NULL);

        node* assign = TBmakeAssign(varlet, expression);
        ASSIGN_TYPE(assign) = SYMBOLTABLEENTRY_TYPE(GLOBDEF_DECL(DECLS_DECL(current_decl)));

        addNodeStatements(assign, funbody);

    }

    current_decl = DECLS_NEXT(current_decl);
  }
  
  if (decls) {
    addNodeStatements(TBmakeReturn(NULL), funbody);
    fundef = TBmakeFundef(T_void, STRcpy("__init"), NULL, funbody, NULL);
    FUNDEF_ISEXPORT(fundef) = TRUE;
  }

  node* top_decl = PROGRAM_DECLS(arg_node);
  while (top_decl) {
    if(DECLS_NEXT(top_decl)) {
      if(NODE_TYPE(DECLS_DECL(DECLS_NEXT(top_decl))) == N_globdef) {
        top_decl = DECLS_NEXT(top_decl);
      } else {
        break;
      }
    } else {
      break;
    }
  }

  node* top_decl_next = DECLS_NEXT(top_decl);
  if (fundef) {
    DECLS_NEXT(top_decl) = TBmakeDecls(fundef, top_decl_next);

  }

  PROGRAM_DECLS(arg_node) = TRAVopt(PROGRAM_DECLS(arg_node), arg_info);

  DBUG_RETURN(arg_node);

}

node *VAfunbody (node *arg_node, info *arg_info){
  
  DBUG_ENTER("MTfunbody");
  
  node* current_vardecl = FUNBODY_VARDECLS(arg_node);

  while (current_vardecl) {

      if(VARDECL_INIT(current_vardecl)) {
          
        //Get all the information needed to make the assign node
        node* expression = VARDECL_INIT(current_vardecl);
        char* temporaryName = STRcat(STRcpy("temp_"), STRitoa(INFO_TEMP(arg_info)));
        INFO_TEMP(arg_info)++;

        // Update current vardecl node.
        VARDECL_NAME(current_vardecl) = STRcpy(temporaryName);
        VARDECL_INIT(current_vardecl) = NULL;
        node* varlet = TBmakeVarlet(temporaryName, VARDECL_DECL(current_vardecl), NULL);
        //node* varlet = TBmakeVarlet(temporaryName, NULL, NULL);

        node* assign = TBmakeAssign(varlet, expression);
        ASSIGN_TYPE(assign) = SYMBOLTABLEENTRY_TYPE(VARDECL_DECL(current_vardecl));


        // Add the newly made assign to the funbody
        addNodeStatements(assign, arg_node);

      }
      
      current_vardecl = VARDECL_NEXT(current_vardecl);
  }


  FUNBODY_LOCALFUNDEFS(arg_node) = TRAVopt(FUNBODY_LOCALFUNDEFS(arg_node), arg_info);

  DBUG_RETURN(arg_node);
  
}


/*
 * Traversal start function
 */

node *VAdoVariableToAssign( node *syntaxtree)
{
  info *arg_info;

  DBUG_ENTER("VAdoVariableToAssign");

  arg_info = MakeInfo();

  TRAVpush( TR_va);
  syntaxtree = TRAVdo( syntaxtree, arg_info);
  TRAVpop();

  DBUG_RETURN( syntaxtree);
}
