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

node *BCcast(node* arg_node, info* arg_info) {

    DBUG_ENTER("BCcast");

    if (NODE_TYPE(CAST_EXPR(arg_node)) == N_bool)
        printf("hooooi\n");

        if (CAST_TYPE(arg_node) == T_int) {

            printf("1\n");

            node* condexpr = TBmakeCondexpr(CAST_EXPR(arg_node), TBmakeNum(1), TBmakeNum(0));
            arg_node = condexpr;

        } else if (CAST_TYPE(arg_node) == T_float) {

            printf("2\n");
            node* condexpr = TBmakeCondexpr(CAST_EXPR(arg_node), TBmakeFloat(1.0), TBmakeFloat(0.0));
            arg_node = condexpr;

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
