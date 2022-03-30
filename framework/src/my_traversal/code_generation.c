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

struct INFO {
  int sum_const;
  int sum_var;
  int sum_store;
  int sum_labels;
};

#define INFO_SUM_C(n) ((n)->sum_const)
#define INFO_SUM_V(n) ((n)->sum_var)
#define INFO_SUM_S(n) ((n)->sum_store)
#define INFO_SUM_L(n) ((n)->sum_labels)

static info *MakeInfo(void) {
  info *result;

  DBUG_ENTER( "MakeInfo");

  result = (info *)MEMmalloc(sizeof(info));
  INFO_SUM_C(result) = 0;
  INFO_SUM_V(result) = 0;
  INFO_SUM_S(result) = 0;
  INFO_SUM_L(result) = 0;

  DBUG_RETURN( result);
}

/*
 * Traversal functions
 */

char* type_to_char(int type) {

  switch(type) {
    case 1 :
      return ("b");
    case 2 :
      return("i");
    case 3 :
      return("f");
    default:
      CTIerror("undefined type");
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
    default:
      CTIerror("undefined type");
    // case BO_and :
    //   return ("and");
    // case BO_or :
    //   return("or");
  }
}

//TODO: monop to char


node *CGprogram(node* arg_node, info* arg_info) {

    DBUG_ENTER("CGprogram");

    PROGRAM_DECLS(arg_node) = TRAVopt(PROGRAM_DECLS(arg_node), arg_info);


    DBUG_RETURN(arg_node);
  
}

extern node *CGfundef (node *arg_node, info *arg_info) {
    DBUG_ENTER("CGfundef");

    INFO_SUM_C(arg_info) = 0;
    INFO_SUM_V(arg_info) = 0;
    INFO_SUM_S(arg_info) = 0;

    printf("%s:\n", FUNDEF_NAME(arg_node));

    FUNDEF_PARAMS(arg_node) = TRAVopt(FUNDEF_PARAMS(arg_node), arg_info);
    FUNDEF_FUNBODY(arg_node) = TRAVopt(FUNDEF_FUNBODY(arg_node), arg_info);


    
    DBUG_RETURN(arg_node);
}

node* CGfuncall(node* arg_node, info* arg_info) {
    DBUG_ENTER("CGfuncall");

    printf("\tjsr %s\n", FUNCALL_NAME(arg_node));

    DBUG_RETURN(arg_node);

}

extern node *CGifelse (node *arg_node, info *arg_info) {
    DBUG_ENTER("CGifelse");



    IFELSE_COND(arg_node) = TRAVdo(IFELSE_COND(arg_node), arg_info);

    int label1 = INFO_SUM_L(arg_info) + 1;
    int label2 = label1 + 1;
    INFO_SUM_L(arg_info) = INFO_SUM_S(arg_info) + 2;

    printf("\tbranch_f L%d\n", label1);

    IFELSE_THEN(arg_node) = TRAVopt(IFELSE_THEN(arg_node), arg_info);

    printf("\tjump L%d\n", label2);

    printf("L%d\n", label1);

    IFELSE_ELSE(arg_node) = TRAVopt(IFELSE_ELSE(arg_node), arg_info);

    printf("L%d\n", label2);

    DBUG_RETURN(arg_node);
}

extern node *CGdowhile(node *arg_node, info *arg_info) {
  DBUG_ENTER("CGdowhile");

  int label = INFO_SUM_L(arg_info) + 1;
  INFO_SUM_L(arg_info) = INFO_SUM_L(arg_info) + 1;

  printf("L%d\n", label);

  DOWHILE_BLOCK(arg_node) = TRAVopt(DOWHILE_BLOCK(arg_node), arg_info);

  DOWHILE_COND(arg_node) = TRAVdo(DOWHILE_COND(arg_node), arg_info);

  printf("\tbranch_f L%d\n", label);

  DBUG_RETURN(arg_node);
}

extern node *CGassign (node *arg_node, info *arg_info) {
    DBUG_ENTER("CGassign");
    
    //ASSIGN_LET(arg_node) = TRAVopt(ASSIGN_LET(arg_node), arg_info);
    ASSIGN_EXPR(arg_node) = TRAVdo(ASSIGN_EXPR(arg_node), arg_info);

    printf("\t%sstore %d\n", type_to_char(ASSIGN_TYPE(arg_node)), INFO_SUM_V(arg_info));

    INFO_SUM_V(arg_info) = INFO_SUM_V(arg_info) + 1;
    INFO_SUM_S(arg_info) = INFO_SUM_S(arg_info) + 1;

    DBUG_RETURN(arg_node);
}

node *CGbinop(node* arg_node, info* arg_info) {
    DBUG_ENTER("CGbinop");

    BINOP_LEFT(arg_node) = TRAVdo(BINOP_LEFT(arg_node), arg_info);
    BINOP_RIGHT(arg_node) = TRAVdo(BINOP_RIGHT(arg_node), arg_info);

    printf("\t%s%s\n", type_to_char(BINOP_SUBTYPE(arg_node)), binop_to_char(BINOP_OP(arg_node)));

    DBUG_RETURN(arg_node);
}

node *CGvar(node* arg_node, info* arg_info) {
    DBUG_ENTER("CGvar");

    printf("\t%sload %d\n", type_to_char(SYMBOLTABLEENTRY_TYPE(VAR_DECL(arg_node))), INFO_SUM_V(arg_info));

    INFO_SUM_V(arg_info) = INFO_SUM_V(arg_info) + 1;

    DBUG_RETURN(arg_node);

}

node* CGnum(node* arg_node, info* arg_info) {
    DBUG_ENTER("CGnum");

    printf("\tiloadc %d\n", INFO_SUM_C(arg_info));

    INFO_SUM_C(arg_info) = INFO_SUM_C(arg_info) + 1;
    

    DBUG_RETURN(arg_node);

}

node* CGfloat(node* arg_node, info* arg_info) {
    DBUG_ENTER("CGfloat");

    printf("\tfloadc %d\n", INFO_SUM_C(arg_info));

    INFO_SUM_C(arg_info) = INFO_SUM_C(arg_info) + 1;

    DBUG_RETURN(arg_node);

}

/*
 * Traversal start function
 */

node *CGdoCodeGeneration( node *syntaxtree)
{
    info *arg_info;
    DBUG_ENTER("CGdoCodeGeneration");
    arg_info = MakeInfo();

    TRAVpush( TR_cg);
    syntaxtree = TRAVdo( syntaxtree, arg_info);
    TRAVpop();

    DBUG_RETURN( syntaxtree);
}
