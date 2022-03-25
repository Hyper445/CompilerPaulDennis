/*****************************************************************************
 *
 * Module: code_gen
 *
 * Prefix: CG
 *
 * Description:
 *
 * This module implements a demo traversal of the abstract syntax tree that 
 * sums up all integer constants and prints the result at the end of the traversal.
 *
 *****************************************************************************/


#include "code_generation.h"

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

char* type_to_char(int type) {

  switch(type) {
    case 0 :
      return("v");
    case 1 :
      return ("b");
    case 2 :
      return("i");
    case 3 :
      return("f");
    case 4 :
      return("u");
  }

}

char* binop_to_char(binop binop) {

  switch(binop) {
    case BO_add :
      return("add");
    case BO_sub :
      return ("sub");
    case BO_mul :
      return("mul");
    case BO_div :
      return("div");
    case BO_mod :
      return("rem");
    case BO_lt :
      return("lt");
    case BO_le :
      return ("le");
    case BO_gt :
      return("gt");
    case BO_ge :
      return("ge");
    case BO_eq :
      return("eq");
    case BO_ne :
      return("ne");
    // case BO_and :
    //   return ("and");
    // case BO_or :
    //   return("or");
  
  }

}

//TODO: monop to char


node *CGprogram(node* arg_node, info* arg_info) {

    DBUG_ENTER("CGprogram");

    printf("\n\n\n testje \n\n\n");

    PROGRAM_DECLS(arg_node) = TRAVopt(PROGRAM_DECLS(arg_node), arg_info);


    DBUG_RETURN(arg_node);
  
}

extern node *CGfundef (node *arg_node, info *arg_info) { DBUG_ENTER("CGfundef"); printf("\n\n\n testje2 \n\n\n");DBUG_RETURN(arg_node);}
extern node *CGassign (node *arg_node, info *arg_info) { DBUG_ENTER("CGassign"); DBUG_RETURN(arg_node);}

node *CGbinop(node* arg_node, info* arg_info) {
    DBUG_ENTER("CGbinop");


    printf(binop_to_char(BINOP_OP(arg_node)));


    DBUG_RETURN(arg_node);
}

node *CGvar(node* arg_node, info* arg_info) {
    DBUG_ENTER("CGvar");

    DBUG_RETURN(arg_node);

}

node* CGnum(node* arg_node, info* arg_info) {
    DBUG_ENTER("CGnum");

    DBUG_RETURN(arg_node);

}

node* CGfloat(node* arg_node, info* arg_info) {
    DBUG_ENTER("CGfloat");

    DBUG_RETURN(arg_node);

}

/*
 * Traversal start function
 */

node *CGdoCodeGeneration( node *syntaxtree)
{
  info *arg_info = NULL;

  DBUG_ENTER("CGdoCodeGeneration");

  TRAVpush( TR_cg);
  syntaxtree = TRAVdo( syntaxtree, arg_info);
  TRAVpop();

  DBUG_RETURN( syntaxtree);
}
