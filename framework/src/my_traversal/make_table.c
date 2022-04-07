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


#include "make_table.h"
#include "make_table_helper.h"
#include "code_generation_helper.h"

#include "lookup_table.h"
#include "types.h"
#include "tree_basic.h"
#include "traverse.h"
#include "dbug.h"
#include "str.h"
#include "string.h"

#include "memory.h"
#include "ctinfo.h"


/*
 * INFO structure
 */

struct INFO {
  type type;
  node* Symboltable;
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

  INFO_ST(result) = NULL;

  DBUG_RETURN( result);
}

/*
 * Traversal functions
 */

node* MTprogram(node *arg_node, info *arg_info) {

  DBUG_ENTER("MTprogram");

  INFO_ST(arg_info) = TBmakeSymboltable(STRcpy("Global"), NULL, NULL, NULL);

  PROGRAM_DECLS(arg_node) = TRAVopt(PROGRAM_DECLS(arg_node), arg_info);

  PROGRAM_SYMBOLTABLE(arg_node) = INFO_ST(arg_info);
  DBUG_RETURN(arg_node);

}

node *MTifelse (node *arg_node, info *arg_info) {
  DBUG_ENTER("MTifelse");

  char* name = STRcpy("ifelse");

  node* parent_table = INFO_ST(arg_info);

  // Creates new scope. Current scope stored in arg_info is set to this new scope
  INFO_ST(arg_info) = TBmakeSymboltable(name, parent_table, NULL, NULL);

  // Traverse through both the 'then' and 'else' block.
  IFELSE_COND(arg_node) = TRAVdo(IFELSE_COND(arg_node), arg_info);
  IFELSE_THEN(arg_node) = TRAVopt(IFELSE_THEN(arg_node), arg_info);
  IFELSE_ELSE(arg_node) = TRAVopt(IFELSE_ELSE(arg_node), arg_info);

  // The scope in arg_info is set back to the scope of the parent.
  INFO_ST(arg_info) = parent_table;

  DBUG_RETURN(arg_node);
}

node *MTfundef (node *arg_node, info *arg_info){
  
  DBUG_ENTER("MTfundef");
  char* name;
  type type;
  
  // When reaching a function definition, add this to the current symbol table
  name = STRcpy(FUNDEF_NAME(arg_node));
  type = FUNDEF_TYPE(arg_node);
  addSymbol(name, type, arg_info, FUNDEF_PARAMS(arg_node), TRUE);

  node* parent_table = INFO_ST(arg_info);

  // Then create a new symbol table for the function.
  if (FUNDEF_PARAMS(arg_node)) {
    INFO_ST(arg_info) = TBmakeSymboltable(STRcpy(FUNDEF_NAME(arg_node)), 
      parent_table, FUNDEF_PARAMS(arg_node), NULL);
  } else {
    INFO_ST(arg_info) = TBmakeSymboltable(STRcpy(FUNDEF_NAME(arg_node)), parent_table, NULL, NULL);
  }
  FUNDEF_SYMBOLTABLE(arg_node) = INFO_ST(arg_info);

  // Add the params to the new symbol table
  if (FUNDEF_PARAMS(arg_node)) {
    node* current_param = FUNDEF_PARAMS(arg_node);
    while (current_param) {
      name = STRcpy(PARAM_NAME(current_param));
      type = PARAM_TYPE(current_param);
      addSymbol(name, type, arg_info, NULL, FALSE);
      current_param = PARAM_NEXT(current_param);
    }
  }

  //If the function has a body, traverse the funbody with the new table
  FUNDEF_PARAMS(arg_node) = TRAVopt(FUNDEF_PARAMS(arg_node), arg_info);
  FUNDEF_FUNBODY(arg_node) = TRAVopt(FUNDEF_FUNBODY(arg_node), arg_info);

  INFO_ST(arg_info) = parent_table;

  DBUG_RETURN(arg_node);
  
}


node *MTglobdecl (node *arg_node, info *arg_info) {

  DBUG_ENTER("MTglobdecl");

  char* name = STRcpy(GLOBDECL_NAME(arg_node));
  type type = GLOBDECL_TYPE(arg_node);
  addSymbol(name, type, arg_info, NULL, FALSE);

  DBUG_RETURN(arg_node);
  
}

node *MTglobdef (node *arg_node, info *arg_info) {
  
  DBUG_ENTER("MTglobdef");

  char* name = STRcpy(GLOBDEF_NAME(arg_node));
  type type = GLOBDEF_TYPE(arg_node);
  addSymbol(name, type, arg_info, NULL, FALSE);

  DBUG_RETURN(arg_node);

}

node *MTvardecl (node *arg_node, info *arg_info) {
  
  DBUG_ENTER("MTvardecl");

  VARDECL_NEXT(arg_node) = TRAVopt(VARDECL_NEXT(arg_node), arg_info);
  VARDECL_INIT(arg_node) = TRAVopt(VARDECL_INIT(arg_node), arg_info);

  char* name = STRcpy(VARDECL_NAME(arg_node));
  type type = VARDECL_TYPE(arg_node);
  addSymbol(name, type, arg_info, NULL, FALSE);

  DBUG_RETURN(arg_node);
  
}

node* MTwhile(node* arg_node, info* arg_info) {

  DBUG_ENTER("MTwhile");

  WHILE_BLOCK(arg_node) = TRAVopt(WHILE_BLOCK(arg_node), arg_info);
  WHILE_COND(arg_node) = TRAVopt(WHILE_COND(arg_node), arg_info);

  DBUG_RETURN(arg_node);

}

// For every function call, a link is added to the function's decleration.
node *MTfuncall(node *arg_node, info *arg_info) {
  DBUG_ENTER("MTfuncall");

  // Traverse through the arguments of the function.
  FUNCALL_ARGS(arg_node) = TRAVopt(FUNCALL_ARGS(arg_node), arg_info);

  DBUG_RETURN(arg_node);
}

// For every varlet, a link is added to the varlet's decleration
node *MTvarlet(node *arg_node, info *arg_info) {
  DBUG_ENTER("MTvarlet");

  DBUG_RETURN(arg_node);
}

node *MTvar(node *arg_node, info *arg_info) {
  DBUG_ENTER("MTvar");

  DBUG_RETURN(arg_node);
}

/*
 * Traversal start function
 */

node *MTdoMakeTable( node *syntaxtree)
{
  info *arg_info;

  DBUG_ENTER("MTdoMakeTable");

  arg_info = MakeInfo();

  TRAVpush( TR_mt);
  syntaxtree = TRAVdo( syntaxtree, arg_info);
  TRAVpop();

  DBUG_RETURN( syntaxtree);
}
