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

void addConstant(node* arg_node, info* arg_info) {
  
  int index = 0;

  if (INFO_C(arg_info)) {

    node* current_constant = INFO_C(arg_info);
    node* previous_constant = current_constant;
    while (current_constant) {
      
      if (NODE_TYPE(CONSTANT_VALUE(current_constant)) == NODE_TYPE(arg_node))

        switch (NODE_TYPE(arg_node)) {

          case N_float:
            if (FLOAT_VALUE(CONSTANT_VALUE(current_constant)) == FLOAT_VALUE(arg_node)) {
              return;
            }

          case N_num:
            if (NUM_VALUE(CONSTANT_VALUE(current_constant)) == NUM_VALUE(arg_node)) {
              return;
            }

          default:
            break;

        }
      
      index++;
      previous_constant = current_constant;
      current_constant = CONSTANT_NEXT(current_constant);
      

    }

    printf("%d added value \n", NUM_VALUE(arg_node));

    CONSTANT_NEXT(previous_constant) = TBmakeConstant(NODE_TYPE(arg_node), arg_node, index, NULL);

  } else {

    printf("%d added value \n", NUM_VALUE(arg_node));
    INFO_C(arg_info) = TBmakeConstant(NODE_TYPE(arg_node), arg_node, index, NULL);

  }


}


node* MCTprogram(node *arg_node, info *arg_info) {

  DBUG_ENTER("MCTprogram");

  PROGRAM_DECLS(arg_node) = TRAVopt(PROGRAM_DECLS(arg_node), arg_info);
  PROGRAM_CONSTANTTABLE(arg_node) = INFO_C(arg_info);

  //arg_node = addConstant(TBmakeFloat(INFO_FLOAT(arg_info)), arg_info);
  addConstant(TBmakeNum(INFO_INT(arg_info)), arg_info);


  DBUG_RETURN(arg_node);

}

node *MCTglobdef (node *arg_node, info *arg_info) {
  
  DBUG_ENTER("MCTglobdef");

  GLOBDEF_INIT(arg_node) = TRAVopt(GLOBDEF_INIT(arg_node), arg_info);

  DBUG_RETURN(arg_node);

}

node *MCTbinop (node* arg_node, info* arg_info) {

  DBUG_ENTER("MCTbinop");

  if (NODE_TYPE(BINOP_LEFT(arg_node)) == NODE_TYPE(BINOP_RIGHT(arg_node))) {

    if (NODE_TYPE(BINOP_LEFT(arg_node)) == N_num) {

      switch (BINOP_OP(arg_node)) {

        case BO_add:
          INFO_INT(arg_info) = NUM_VALUE(BINOP_LEFT(arg_node)) + NUM_VALUE(BINOP_RIGHT(arg_node));
          break;

        case BO_mul:
          printf("Hier moet ie dus zijn\n\n");
          INFO_INT(arg_info) = NUM_VALUE(BINOP_LEFT(arg_node)) * NUM_VALUE(BINOP_RIGHT(arg_node));
          printf("%d = resultaat\n", INFO_INT(arg_info));
          break;

        case BO_div:
          INFO_INT(arg_info) = NUM_VALUE(BINOP_LEFT(arg_node)) / NUM_VALUE(BINOP_RIGHT(arg_node));
          break;

        case BO_sub:
          INFO_INT(arg_info) = NUM_VALUE(BINOP_LEFT(arg_node)) - NUM_VALUE(BINOP_RIGHT(arg_node));
          break;

        case BO_mod:
          INFO_INT(arg_info) = NUM_VALUE(BINOP_LEFT(arg_node)) % NUM_VALUE(BINOP_RIGHT(arg_node));
          break;

      }

    }

  }

  BINOP_LEFT(arg_node) = TRAVopt(BINOP_LEFT(arg_node), arg_info);
  BINOP_RIGHT(arg_node) = TRAVopt(BINOP_RIGHT(arg_node), arg_info);
  
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

  addConstant(arg_node, arg_info);

  DBUG_RETURN(arg_node);

}

node* MCTfloat(node* arg_node, info* arg_info) {

  DBUG_ENTER("MCTfloat");

  addConstant(arg_node, arg_info);

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
