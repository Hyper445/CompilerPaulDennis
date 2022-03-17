/*****************************************************************************
 *
 * Module: enter_symbol_table
 *
 * Prefix: EST
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
  node* Symboltable;
  node* self;
  node* next;
};



/*
 * INFO macros
 */

#define INFO_ST(n) ((n)->Symboltable)
#define INFO_NEXT(n) ((n)->next)


/*
 * INFO functions
 */


static info *MakeInfo(void)
{
  info *result;

  DBUG_ENTER( "MakeInfo");

  result = (info *)MEMmalloc(sizeof(info));

  INFO_ST(result) = TBmakeSymboltable("Global", NULL, NULL);
  INFO_NEXT(result) = NULL;

  DBUG_RETURN( result);
}

static info *FreeInfo( info *info)
{
  DBUG_ENTER ("FreeInfo");

  info = MEMfree( info);

  DBUG_RETURN( info);
}

void addNode(node* assign, node* funbody) {

    node* current_stmt = FUNBODY_STMTS(funbody);

    if (current_stmt) {
        while (STMTS_NEXT(current_stmt) != NULL) {
            current_stmt = STMTS_NEXT(current_stmt);
        }
        STMTS_NEXT(current_stmt) = TBmakeStmts(assign, NULL);
    } else {
        FUNBODY_STMTS(funbody) = TBmakeStmts(assign, NULL);
    }

}

/*
 * Traversal functions
 */

node *VAfunbody (node *arg_node, info *arg_info){
  
  DBUG_ENTER("MTfundef");
  
  node* current_vardecl = FUNBODY_VARDECLS(arg_node);

  while (current_vardecl) {

      if(VARDECL_INIT(current_vardecl)) {
          
        //Get all the information needed to make the assign node
        node* expression = VARDECL_INIT(current_vardecl);
        char* name = STRcpy(VARDECL_NAME(current_vardecl));
        char* temporaryName = STRcat("temp", name);

        // Update current vardecl node.
        VARDECL_NAME(current_vardecl) = STRcpy(temporaryName);
        VARDECL_INIT(current_vardecl) = NULL;
        node* varlet = TBmakeVarlet(temporaryName, NULL, NULL);
        node* assign = TBmakeAssign(varlet, expression);

        // Add the newly made assign to the funbody
        addNode(assign, arg_node);

      }
      
      current_vardecl = VARDECL_NEXT(current_vardecl);
  }

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
