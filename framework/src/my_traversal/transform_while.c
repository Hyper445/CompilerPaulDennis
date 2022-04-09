/*****************************************************************************
 *
 * Module: tranform_while
 *
 * Prefix: TW
 *
 * Description:
 *
 * This module implements a demo traversal of the abstract syntax tree that 
 * sums up all integer constants and prints the result at the end of the traversal.
 *
 *****************************************************************************/


#include "transform_while.h"

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

static info *FreeInfo( info *info)
{
  DBUG_ENTER ("FreeInfo");

  info = MEMfree( info);

  DBUG_RETURN( info);
}


/*
 * Traversal functions
 */

node *TWwhile( node* arg_node, info * arg_info) {

  DBUG_ENTER("TWwhile");

  arg_node = TBmakeDowhile(WHILE_COND(arg_node), WHILE_BLOCK(arg_node));

  DBUG_RETURN(arg_node);

}


/*
 * Traversal start function
 */

node *TWdoTransformWhile( node *syntaxtree)
{

  DBUG_ENTER("TWdoTransformWhile");

  info *arg_info = NULL;

  TRAVpush( TR_tw);
  syntaxtree = TRAVdo( syntaxtree, arg_info);
  TRAVpop();

  DBUG_RETURN( syntaxtree);
}
