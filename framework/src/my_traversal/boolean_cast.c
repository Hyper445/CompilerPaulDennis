/*****************************************************************************
 *
 * Module: boolean_cast
 *
 * Prefix: BC
 *
 * Description:
 *
 * Whenever a cast is executed on a boolean, this traversal transforms it into a
 * conditional expression that returns ints 1-0 for Boolean values true-false 
 * respectively, or float 1.0-0.0
 *
 *****************************************************************************/


#include "boolean_cast.h"

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

// Transforms a cast into a conditional expression.
node *BCcast(node* arg_node, info* arg_info) {

    DBUG_ENTER("BCcast");

    if (NODE_TYPE(CAST_EXPR(arg_node)) == N_bool){

        if (CAST_TYPE_LEFT(arg_node) == T_int) {
            node* condexpr = TBmakeCondexpr(CAST_EXPR(arg_node), TBmakeNum(1), TBmakeNum(0));
            arg_node = condexpr;

        } else if (CAST_TYPE_LEFT(arg_node) == T_float) {
            node* condexpr = TBmakeCondexpr(CAST_EXPR(arg_node), TBmakeFloat(1.0), TBmakeFloat(0.0));
            arg_node = condexpr;

        }
    }
    
    DBUG_RETURN(arg_node);
}


/*
 * Traversal start function
 */

node *BCdoBooleanCast( node *syntaxtree)
{
  info *arg_info = NULL;

  DBUG_ENTER("BCdoBooleanCast");

  TRAVpush( TR_bc);
  syntaxtree = TRAVdo( syntaxtree, arg_info);
  TRAVpop();

  DBUG_RETURN( syntaxtree);
}
