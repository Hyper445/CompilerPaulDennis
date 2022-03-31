/*****************************************************************************
 *
 * Module: make_constant_table
 *
 * Prefix: MCT
 *
 * Description:
 *
 * This module implements a demo traversal of the abstract syntax tree that 
 * sums up all integer constants and prints the result at the end of the traversal.
 *
 *****************************************************************************/


#include "make_constant_table.h"

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
};



/*
 * INFO macros
 */

#define INFO_C(n) ((n)->constant)


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

node* MCTprogram(node *arg_node, info *arg_info) {

  DBUG_ENTER("MCTprogram");

  PROGRAM_DECLS(arg_node) = TRAVopt(PROGRAM_DECLS(arg_node), arg_info);
  PROGRAM_CONSTANTTABLE(arg_node) = INFO_C(arg_info);
  DBUG_RETURN(arg_node);

}

node *MCTglobdef (node *arg_node, info *arg_info) {
  
  DBUG_ENTER("MCTglobdef");

  GLOBDEF_INIT(arg_node) = TRAVopt(GLOBDEF_INIT(arg_node), arg_info);

  DBUG_RETURN(arg_node);

}

node *MCTvardecl (node *arg_node, info *arg_info) {
  
  DBUG_ENTER("MCTvardecl");

  VARDECL_INIT(arg_node) = TRAVopt(VARDECL_INIT(arg_node), arg_info);
  VARDECL_NEXT(arg_node) = TRAVopt(VARDECL_NEXT(arg_node), arg_info);

  DBUG_RETURN(arg_node);
  
}

node* MCTnum(node* arg_node, info* arg_info) {


  DBUG_ENTER("MCTnum");
  int index = 0;

  if (INFO_C(arg_info)) {

    node* current_constant = INFO_C(arg_info);
    node* previous_constant = current_constant;
    while (current_constant) {
      
      if (NODE_TYPE(CONSTANT_VALUE(current_constant)) == NODE_TYPE(arg_node))
        switch (NODE_TYPE(arg_node)) {

          case N_float:
            if (FLOAT_VALUE(CONSTANT_VALUE(current_constant)) == FLOAT_VALUE(arg_node)) {
              DBUG_RETURN(arg_node);;
            }

          case N_num:
            if (NUM_VALUE(CONSTANT_VALUE(current_constant)) == NUM_VALUE(arg_node)) {
              DBUG_RETURN(arg_node);
            }

          default:
            break;

        }
      
      index++;
      previous_constant = current_constant;
      current_constant = CONSTANT_NEXT(current_constant);
      

    }

    CONSTANT_NEXT(previous_constant) = TBmakeConstant(T_int, arg_node, index, NULL);

  } else {

    INFO_C(arg_info) = TBmakeConstant(T_int, arg_node, index, NULL);

  }

  DBUG_RETURN(arg_node);

}

node* MCTfloat(node* arg_node, info* arg_info) {

  DBUG_ENTER("MCTfloat");
  int index = 0;

  if (INFO_C(arg_info)) {
    index++;
    node* current_constant = INFO_C(arg_info);
    while (CONSTANT_NEXT(current_constant) != NULL) {
      
      if (NODE_TYPE(CONSTANT_VALUE(current_constant)) == NODE_TYPE(arg_node))
        switch (NODE_TYPE(arg_node)) {

          case N_float:
            if (FLOAT_VALUE(CONSTANT_VALUE(current_constant)) == FLOAT_VALUE(arg_node)) {
              DBUG_RETURN(arg_node);;
            }

          case N_num:
            if (NUM_VALUE(CONSTANT_VALUE(current_constant)) == NUM_VALUE(arg_node)) {
              DBUG_RETURN(arg_node);
            }

          default:
            break;

        }
      
      index++;
      current_constant = CONSTANT_NEXT(current_constant);

    }

    CONSTANT_NEXT(current_constant) = TBmakeConstant(T_float, arg_node, index, NULL);

  } else {

    INFO_C(arg_info) = TBmakeConstant(T_float, arg_node, index, NULL);

  }

  DBUG_RETURN(arg_node);

}


/*
 * Traversal start function
 */

node *MCTdoMakeConstantTable( node *syntaxtree)
{
  info *arg_info;

  DBUG_ENTER("MCTdoMakeConstantTable");

  arg_info = MakeInfo();

  TRAVpush( TR_mct);
  syntaxtree = TRAVdo( syntaxtree, arg_info);
  TRAVpop();

  DBUG_RETURN( syntaxtree);
}
