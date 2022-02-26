/*****************************************************************************
 *
 * Module: reduce_strength
 *
 * Prefix: RS
 *
 * Description:
 *
 * This module implements a demo traversal of the abstract syntax tree that 
 * reduces the strength of multiplication
 *
 *****************************************************************************/


#include "reduce_strength.h"

#include "types.h"
#include "tree_basic.h"
#include "traverse.h"
#include "dbug.h"

#include "str.h"
#include "memory.h"


/*
 * Traversal functions
 */

node* makeNodeVar(char* var, int num) {

  if (num == 0) {
    return TBmakeBinop(BO_add, TBmakeVar(var), TBmakeVar(var));
  } else {
    return TBmakeBinop(BO_add, makeNodeVar(var, num - 1), TBmakeVar(var));
  }
}

node* createAddNodesVar(node* n, int num, node* nodevar) {

  char* var = VAR_NAME(nodevar);

  if (num > 2) {
    n = TBmakeBinop(BO_add, makeNodeVar(var, num - 3), TBmakeVar(var)); 

  } else if (num == 2) {
    n = TBmakeBinop(BO_add, TBmakeVar(var), TBmakeVar(var)); 
  }

  return(n);
}



node *RSbinop( node *arg_node, info *arg_info)
{

  BINOP_LEFT(arg_node) = TRAVdo(BINOP_LEFT(arg_node), arg_info);
  BINOP_RIGHT(arg_node) = TRAVdo(BINOP_RIGHT(arg_node), arg_info);

  node *n;
  
  // The 3 could be replaced to set a different limit to the multiplier amount
  if (BINOP_OP( arg_node) == BO_mul) {
    if ((NODE_TYPE( BINOP_LEFT( arg_node)) == N_var)
	  && (NODE_TYPE( BINOP_RIGHT( arg_node)) == N_num) 
    && NUM_VALUE(BINOP_RIGHT(arg_node)) <= 3) {
          n = createAddNodesVar(arg_node, NUM_VALUE(BINOP_RIGHT(arg_node)), BINOP_LEFT(arg_node)); 
    }
    else if  ((NODE_TYPE( BINOP_LEFT( arg_node)) == N_num)
	      && (NODE_TYPE( BINOP_RIGHT( arg_node)) == N_var)
        && NUM_VALUE(BINOP_LEFT(arg_node)) <= 3) {
          n = createAddNodesVar(arg_node, NUM_VALUE(BINOP_LEFT(arg_node)), BINOP_RIGHT(arg_node));   
    }
    // When left variable is same as right variable, 2 variables need to be multiplied, hence the 2
    else if  ((NODE_TYPE( BINOP_LEFT( arg_node)) == N_var)
	      && (NODE_TYPE( BINOP_RIGHT( arg_node)) == N_var) 
        && STReq( VAR_NAME( BINOP_LEFT( arg_node)), VAR_NAME( BINOP_RIGHT( arg_node)))) {
          n = createAddNodesVar(arg_node, 2, BINOP_LEFT(arg_node));
        }

    else {
      n = arg_node;
    }
  } else {
    n = arg_node;
  }

  return (n);
}



/*
 * Traversal start function
 */

node *RSdoReduceStrength( node *syntaxtree)
{
  DBUG_ENTER("RIdoReduceStrength");

  TRAVpush( TR_rs);   // Push traversal "rs" as defined in ast.xml

  syntaxtree = TRAVdo( syntaxtree, NULL);   // Initiate ast traversal

  TRAVpop();          // Pop current traversal

  DBUG_RETURN( syntaxtree);
}