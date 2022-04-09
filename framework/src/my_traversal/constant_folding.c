/*****************************************************************************
 *
 * Module: constant_folding
 *
 * Prefix: CF
 *
 * Description:
 *
 * This module implements a demo traversal of the abstract syntax tree that 
 * sums up all integer constants and prints the result at the end of the traversal.
 *
 *****************************************************************************/


#include "constant_folding.h"

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
  node* constant;
  int int_result;
  float float_result;
};



/*
 * INFO macros
 */

#define INFO_C(n) ((n)->constant)
#define INFO_INT(n) ((n)->int_result)
#define INFO_FLOAT(n) ((n)->float_result)


/*
 * INFO functions
 */


static info *MakeInfo(void)
{
  info *result;

  DBUG_ENTER( "MakeInfo");

  result = (info *)MEMmalloc(sizeof(info));

  INFO_C(result) = NULL;

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


// node *CFglobdef (node *arg_node, info *arg_info) {
  
//   DBUG_ENTER("MCTglobdef");

//   GLOBDEF_INIT(arg_node) = TRAVopt(GLOBDEF_INIT(arg_node), arg_info);

//   DBUG_RETURN(arg_node);

// }

node *CFbinop (node* arg_node, info* arg_info) {

  DBUG_ENTER("MCTbinop");

  BINOP_LEFT(arg_node) = TRAVopt(BINOP_LEFT(arg_node), arg_info);
  BINOP_RIGHT(arg_node) = TRAVopt(BINOP_RIGHT(arg_node), arg_info);

  if (BINOP_OP(arg_node) > 4) {
    DBUG_RETURN(arg_node);
  }

  if (NODE_TYPE(BINOP_LEFT(arg_node)) == NODE_TYPE(BINOP_RIGHT(arg_node))) {
    if (NODE_TYPE(BINOP_LEFT(arg_node)) == N_num) {
      switch (BINOP_OP(arg_node)) {
        case BO_add:
          arg_node = TBmakeNum(NUM_VALUE(BINOP_LEFT(arg_node)) + NUM_VALUE(BINOP_RIGHT(arg_node)));
          break;

        case BO_mul:
          arg_node = TBmakeNum(NUM_VALUE(BINOP_LEFT(arg_node)) * NUM_VALUE(BINOP_RIGHT(arg_node)));
          break;

        case BO_div:
          arg_node = TBmakeNum(NUM_VALUE(BINOP_LEFT(arg_node)) / NUM_VALUE(BINOP_RIGHT(arg_node)));
          break;

        case BO_sub:
          arg_node = TBmakeNum(NUM_VALUE(BINOP_LEFT(arg_node)) - NUM_VALUE(BINOP_RIGHT(arg_node)));
          break;

        case BO_mod:
          arg_node = TBmakeNum(NUM_VALUE(BINOP_LEFT(arg_node)) % NUM_VALUE(BINOP_RIGHT(arg_node)));
          break;
        default:
          CTIerror("unvalid node type (constant_folding)");
          break;
      }

    }
    else if (NODE_TYPE(BINOP_LEFT(arg_node)) == N_float) {
      switch (BINOP_OP(arg_node)) {
        case BO_add:
          arg_node = TBmakeFloat(FLOAT_VALUE(BINOP_LEFT(arg_node)) + FLOAT_VALUE(BINOP_RIGHT(arg_node)));
          break;

        case BO_mul:
          arg_node = TBmakeFloat(FLOAT_VALUE(BINOP_LEFT(arg_node)) * FLOAT_VALUE(BINOP_RIGHT(arg_node)));
          break;

        case BO_div:
          arg_node = TBmakeFloat(FLOAT_VALUE(BINOP_LEFT(arg_node)) / FLOAT_VALUE(BINOP_RIGHT(arg_node)));
          break;

        case BO_sub:
          arg_node = TBmakeFloat(FLOAT_VALUE(BINOP_LEFT(arg_node)) - FLOAT_VALUE(BINOP_RIGHT(arg_node)));
          break;

        default:
          CTIerror("unvalid node type (constant_folding)");
          break;
      }

    }

  }
  
  DBUG_RETURN(arg_node);

}

// node *CFvardecl (node *arg_node, info *arg_info) {
  
//   DBUG_ENTER("MCTvardecl");

//   VARDECL_INIT(arg_node) = TRAVopt(VARDECL_INIT(arg_node), arg_info);
//   VARDECL_NEXT(arg_node) = TRAVopt(VARDECL_NEXT(arg_node), arg_info);

//   DBUG_RETURN(arg_node);
  
// }


/*
 * Traversal start function
 */

node *CFdoConstantFolding( node *syntaxtree)
{
  info *arg_info;

  DBUG_ENTER("CFdoConstantFolding");

  arg_info = MakeInfo();

  TRAVpush( TR_cf);
  syntaxtree = TRAVdo( syntaxtree, arg_info);
  TRAVpop();

  DBUG_RETURN( syntaxtree);
}
