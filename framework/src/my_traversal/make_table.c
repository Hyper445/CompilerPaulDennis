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
};



/*
 * INFO macros
 */

#define INFO_ST(n) ((n)->Symboltable)


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

static info *FreeInfo( info *info)
{
  DBUG_ENTER ("FreeInfo");

  info = MEMfree( info);

  DBUG_RETURN( info);
}


/*
 * Traversal functions
 */

node *MTprogram (node *arg_node, info *arg_info) {
  
  DBUG_ENTER("MTprogram");
  DBUG_RETURN(arg_node);
  
}
node *MTfundef (node *arg_node, info *arg_info){
  
  DBUG_ENTER("MTfundef");
  DBUG_RETURN(arg_node);
  
}
node *MTglobdecl (node *arg_node, info *arg_info){return arg_node;}
node *MTglobdef (node *arg_node, info *arg_info){return arg_node;}
node *MTvardecl (node *arg_node, info *arg_info){return arg_node;}


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
