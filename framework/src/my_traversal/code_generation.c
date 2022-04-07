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
#include "make_table_helper.h"
#include "code_generation_helper.h"
#include "print.h"

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
  node* constant_table;
  node* global_st;
  node* current_st;

};

#define INFO_SUM_C(n) ((n)->sum_const)
#define INFO_SUM_V(n) ((n)->sum_var)
#define INFO_SUM_S(n) ((n)->sum_store)
#define INFO_SUM_L(n) ((n)->sum_labels)
#define INFO_CT(n) ((n)->constant_table)
#define INFO_GST(n) ((n)->global_st)
#define INFO_CST(n) ((n)->current_st)

static info *MakeInfo(void) {
  info *result;

  DBUG_ENTER( "MakeInfo");

  result = (info *)MEMmalloc(sizeof(info));
  INFO_CT(result) = NULL;
  INFO_GST(result) = NULL;
  INFO_CST(result) = NULL;
  INFO_SUM_C(result) = 0;
  INFO_SUM_V(result) = 0;
  INFO_SUM_S(result) = 0;
  INFO_SUM_L(result) = 0;

  DBUG_RETURN( result);
}

/*
 * Traversal functions
 */

// Get the index of the global table
int functions_amount(node* GST) {

  int amount = 0;
  node* stEntry = SYMBOLTABLE_ENTRIES(GST);

  while (stEntry) {
    if (SYMBOLTABLEENTRY_PARAMS(stEntry)) {
      amount++;
    }

    stEntry = SYMBOLTABLEENTRY_NEXT(stEntry);

  }

  return amount;

}

node *CGprogram(node* arg_node, info* arg_info) {

    DBUG_ENTER("CGprogram");


    INFO_CT(arg_info) = PROGRAM_CONSTANTTABLE(arg_node);
    INFO_GST(arg_info) = PROGRAM_SYMBOLTABLE(arg_node);
    INFO_CST(arg_info) = PROGRAM_SYMBOLTABLE(arg_node);
    PROGRAM_DECLS(arg_node) = TRAVopt(PROGRAM_DECLS(arg_node), arg_info);

    printf("\n");
    print_constants(INFO_CT(arg_info));

    node *current_decls = PROGRAM_DECLS(arg_node);
    
    while (current_decls) {
      node *current_decl = DECLS_DECL(current_decls);
      if (current_decl) {
        if (NODE_TYPE(current_decl) == N_fundef && FUNDEF_ISEXPORT(current_decl) == TRUE) {

          printf(".exportfun \"%s\" %s %s\n", FUNDEF_NAME(current_decl), 
            type_to_string(FUNDEF_TYPE(current_decl)), FUNDEF_NAME(current_decl));

        }

        current_decls = DECLS_NEXT(current_decls);

      }

    }

    print_funs(PROGRAM_SYMBOLTABLE(arg_node));
    print_globals(PROGRAM_SYMBOLTABLE(arg_node));

    DBUG_RETURN(arg_node);
  
}

extern node *CGfundef (node *arg_node, info *arg_info) {
    DBUG_ENTER("CGfundef");

    INFO_CST(arg_info) = FUNDEF_SYMBOLTABLE(arg_node);

    printf("\n%s:\n", FUNDEF_NAME(arg_node));

    // Calculate number of vardecls in funbody.
    int sum_vardecls = 0;
    node *body = FUNDEF_FUNBODY(arg_node);
    node* current_vardecl = NULL;
    if (body) {
      current_vardecl = FUNBODY_VARDECLS(body);
    }
    
    while(current_vardecl != NULL) {
      sum_vardecls = sum_vardecls + 1;
      current_vardecl = VARDECL_NEXT(current_vardecl);
    }

    // Print esr if necessarily.
    if(sum_vardecls != 0) {
      printf("\tesr %d\n", sum_vardecls);
    }
    

    // traverse through paramaters.
    FUNDEF_PARAMS(arg_node) = TRAVopt(FUNDEF_PARAMS(arg_node), arg_info);

    if (body) {
      // Traverse through vardecls and statements.
      FUNBODY_VARDECLS(body) = TRAVopt(FUNBODY_VARDECLS(body), arg_info);
      FUNBODY_STMTS(body) = TRAVopt(FUNBODY_STMTS(body), arg_info);
      // Traverse through the local fundefs
      FUNBODY_LOCALFUNDEFS(body) = TRAVopt(FUNBODY_LOCALFUNDEFS(body), arg_info);

    }
    
    DBUG_RETURN(arg_node);
}

node* CGfuncall(node* arg_node, info* arg_info) {
    DBUG_ENTER("CGfuncall");

    node *arg = FUNCALL_ARGS(arg_node);
    int arg_amount = 0;
    while (arg) {

      arg_amount++;
      arg = EXPRS_NEXT(arg);

    }


    printf("\tisr \n");
    FUNCALL_ARGS(arg_node) = TRAVopt(FUNCALL_ARGS(arg_node), arg_info);

    printf("\tjsr %d %s\n", arg_amount, FUNCALL_NAME(arg_node));
    printf("\tipop\n");

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

extern node *CGcast(node *arg_node, info *arg_info) {
  DBUG_ENTER("CGcast");

  CAST_EXPR(arg_node) = TRAVdo(CAST_EXPR(arg_node), arg_info);

  type old_type = CAST_TYPE_RIGHT(arg_node);
  type new_type = CAST_TYPE_LEFT(arg_node);
  printf("\t%s2%s\n", type_to_char(old_type), type_to_char(new_type));

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

    if(optimise_assign(arg_node, INFO_CT(arg_info)) == 1) {
      DBUG_RETURN(arg_node);
    }

    ASSIGN_EXPR(arg_node) = TRAVdo(ASSIGN_EXPR(arg_node), arg_info);

    if (ASSIGN_LET(arg_node)) {

      if (get_entry_node(VARLET_DECL(ASSIGN_LET(arg_node)), INFO_GST(arg_info), FALSE)) {
        
        int fun_amount = functions_amount(INFO_GST(arg_info));
        printf("\t%sstoreg %d\n", type_to_char(ASSIGN_TYPE(arg_node)), 
          SYMBOLTABLEENTRY_INDEXLEVEL(VARLET_DECL(ASSIGN_LET(arg_node))) - fun_amount);

      }
      else {
        printf("\t%sstore %d\n", type_to_char(ASSIGN_TYPE(arg_node)), 
          SYMBOLTABLEENTRY_INDEXLEVEL(VARLET_DECL(ASSIGN_LET(arg_node))));
      }

    } else {
      printf("\t%sstore %d\n", type_to_char(ASSIGN_TYPE(arg_node)), 
        SYMBOLTABLEENTRY_INDEXLEVEL(VARLET_DECL(ASSIGN_LET(arg_node))));
    }

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

node *CGreturn(node* arg_node, info* arg_info) {
    DBUG_ENTER("CGreturn");

    RETURN_EXPR(arg_node) = TRAVopt(RETURN_EXPR(arg_node), arg_info);
    if (RETURN_EXPR(arg_node)) {
      printf("\t%sreturn\n", type_to_char(RETURN_TYPE(arg_node)));

    } else {
      printf("\treturn\n");
    }

    DBUG_RETURN(arg_node);
}

node *CGvar(node* arg_node, info* arg_info) {
    DBUG_ENTER("CGvar");


    node* st_entry = get_entry(VAR_NAME(arg_node), INFO_CST(arg_info), FALSE);

    if (get_entry_node(VAR_DECL(arg_node), INFO_GST(arg_info), FALSE)) {

      printf("\t%sloadg %d\n", type_to_char(SYMBOLTABLEENTRY_TYPE(VAR_DECL(arg_node))), 
        SYMBOLTABLEENTRY_INDEXLEVEL(VAR_DECL(arg_node)));

    } else if (st_entry == VAR_DECL(arg_node) && SYMBOLTABLEENTRY_INDEXLEVEL(VAR_DECL(arg_node)) > 3) {
      
      printf("\t%sload %d\n", type_to_char(SYMBOLTABLEENTRY_TYPE(VAR_DECL(arg_node))), 
        SYMBOLTABLEENTRY_INDEXLEVEL(VAR_DECL(arg_node)));

    } else if (st_entry == VAR_DECL(arg_node) && SYMBOLTABLEENTRY_INDEXLEVEL(VAR_DECL(arg_node)) <= 3) {
      char* optimised_string = optimise_constant(arg_node);
      printf("\t%s%s\n", type_to_char(SYMBOLTABLEENTRY_TYPE(VAR_DECL(arg_node))), optimised_string);

    }

    // if (global_index(VAR_NAME(arg_node), arg_info) != -1) {

    //   printf("\t%sloadg %d\n", type_to_char(SYMBOLTABLEENTRY_TYPE(VAR_DECL(arg_node))), 
    //     global_index(VAR_NAME(arg_node), arg_info));

    // } else {
    
    // }

    INFO_SUM_V(arg_info) = INFO_SUM_V(arg_info) + 1;

    DBUG_RETURN(arg_node);

}

node* CGnum(node* arg_node, info* arg_info) {
    DBUG_ENTER("CGnum");

    node* constant_table = in_table(arg_node, INFO_CT(arg_info));
    if (constant_table) {

      printf("\tiloadc %d\n", CONSTANT_INDEX(constant_table));
 
    } else {

      char* optimisedCode = optimise_constant(arg_node); 
      printf("%s\n", optimisedCode);
    
    }

    // if (constant_table) {
    //   printf("\tiloadc %d\n", CONSTANT_INDEX(constant_table));

    // } else {
    //   printf("\tiloadc %d\n", 0);
    // }

    // printf("\tiloadc %d\n", INFO_SUM_C(arg_info));
    //printf("\tiloadc %d\n", CONSTANT_INDEX(constant_table));

    INFO_SUM_C(arg_info) = INFO_SUM_C(arg_info) + 1;
    

    DBUG_RETURN(arg_node);

}

node* CGfloat(node* arg_node, info* arg_info) {
    DBUG_ENTER("CGfloat");

    node* constant_table = in_table(arg_node, INFO_CT(arg_info));
    if (constant_table) {

      printf("\tfloadc %d\n", CONSTANT_INDEX(constant_table));
 
    } else {
      char* optimisedCode = optimise_constant(arg_node); 
      printf("%s\n", optimisedCode);
    
    }

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
