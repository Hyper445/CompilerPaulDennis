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


#include "boolean_junction.h"

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
 * Traversal functions
 */

node *BJbinop (node *arg_node, info *arg_info){
  
  DBUG_ENTER("BJbinop");


    if (BINOP_OP(arg_node) == BO_and) {
      
        node* condexpr = TBmakeCondexpr(BINOP_LEFT(arg_node), BINOP_RIGHT(arg_node), TBmakeBool(FALSE));
        arg_node = condexpr;

    } else if (BINOP_OP(arg_node) == BO_or) {

        node* condexpr = TBmakeCondexpr(BINOP_LEFT(arg_node), TBmakeBool(FALSE), BINOP_RIGHT(arg_node));
        arg_node = condexpr;

    }
    

  DBUG_RETURN(arg_node);
  
}


/*
 * Traversal start function
 */

node *BJdoBooleanJunction( node *syntaxtree)
{
  info *arg_info = NULL;

  DBUG_ENTER("BJdoBooleanJunction");

  TRAVpush( TR_bj);
  syntaxtree = TRAVdo( syntaxtree, arg_info);
  TRAVpop();

  DBUG_RETURN( syntaxtree);
}
