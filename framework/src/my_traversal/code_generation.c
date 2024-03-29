/*****************************************************************************
 *
 * Module: code_generations
 *
 * Prefix: CG
 *
 * Description:
 *
 * This moduel writes the assembly code to either a file or to the standard
 * output if no file is given as an argument.
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
#include "string.h"

#include "memory.h"
#include "ctinfo.h"

struct INFO {
  int sum_const;
  int sum_var;
  int sum_store;
  int sum_while;
  int sum_labels;
  node* constant_table;
  node* global_st;
  node* current_st;
  node* import_table;
  node* export_table;

};

#define INFO_SUM_C(n) ((n)->sum_const)
#define INFO_SUM_V(n) ((n)->sum_var)
#define INFO_SUM_S(n) ((n)->sum_store)
#define INFO_SUM_L(n) ((n)->sum_labels)
#define INFO_SUM_WHILE(n) ((n)->sum_while)
#define INFO_CT(n) ((n)->constant_table)
#define INFO_IMP(n) ((n)->import_table)
#define INFO_EXPT(n) ((n)->export_table)
#define INFO_GST(n) ((n)->global_st)
#define INFO_CST(n) ((n)->current_st)

static info *MakeInfo(void) {
  info *result;

  DBUG_ENTER( "MakeInfo");

  result = (info *)MEMmalloc(sizeof(info));
  INFO_CT(result) = NULL;
  INFO_IMP(result) = NULL;
  INFO_EXPT(result) = NULL;
  INFO_GST(result) = NULL;
  INFO_CST(result) = NULL;
  INFO_SUM_WHILE(result) = 1;
  INFO_SUM_C(result) = 0;
  INFO_SUM_V(result) = 0;
  INFO_SUM_S(result) = 0;
  INFO_SUM_L(result) = 0;

  DBUG_RETURN( result);
}

// Gets the number of import functions.
int functions_amount(node* GST) {

  int amount = 0;
  node* stEntry = SYMBOLTABLE_ENTRIES(GST);

  while (stEntry) {
    if (SYMBOLTABLEENTRY_FUNDEF(stEntry) && FUNDEF_ISEXTERN(SYMBOLTABLEENTRY_FUNDEF(stEntry))) {
      amount++;
    }

    stEntry = SYMBOLTABLEENTRY_NEXT(stEntry);

  }

  return amount;
}

/*
 * Traversal functions
 */

// Creates and adds required tables to arg_info. Writes exports,
// globals and imports to output after assembly instructions have
// been generated.
node *CGprogram(node* arg_node, info* arg_info) {

    DBUG_ENTER("CGprogram");

    INFO_CT(arg_info) = PROGRAM_CONSTANTTABLE(arg_node);
    INFO_EXPT(arg_info) = PROGRAM_EXPORTTABLE(arg_node);
    INFO_IMP(arg_info) = PROGRAM_EXTERNTABLE(arg_node);
    INFO_GST(arg_info) = PROGRAM_SYMBOLTABLE(arg_node);
    INFO_CST(arg_info) = PROGRAM_SYMBOLTABLE(arg_node);
    PROGRAM_DECLS(arg_node) = TRAVopt(PROGRAM_DECLS(arg_node), arg_info);

    write_assembly("\n");
    print_constants(INFO_CT(arg_info));

    node *current_decls = PROGRAM_DECLS(arg_node);

    print_exports(current_decls, PROGRAM_EXPORTTABLE(arg_node));
    print_globals(PROGRAM_SYMBOLTABLE(arg_node));
    print_imports(PROGRAM_EXTERNTABLE(arg_node));

    DBUG_RETURN(arg_node);
}

// Writes the esr statemnt and traverses through exprs stmts and fundefs
// In correct order.
extern node *CGfundef (node *arg_node, info *arg_info) {
    DBUG_ENTER("CGfundef");

    INFO_CST(arg_info) = FUNDEF_SYMBOLTABLE(arg_node);
    bool isImport = (in_import_table(arg_node, INFO_IMP(arg_info)) != NULL);

    node *body = FUNDEF_FUNBODY(arg_node);
    if (body || !isImport) {
      write_assembly(STRcat(FUNDEF_NAME(arg_node), ":\n"));
    }

    // Calculate number of vardecls in funbody.
    int sum_vardecls = 0;
    node* current_vardecl = NULL;
    if (body) {
      current_vardecl = FUNBODY_VARDECLS(body);
    }
    
    while(current_vardecl != NULL) {
      sum_vardecls = sum_vardecls + 1;
      current_vardecl = VARDECL_NEXT(current_vardecl);
    }

    // Print esr if necessary.
    if(sum_vardecls != 0) {
      write_assembly(STRcatn(3,"\tesr ", STRitoa(sum_vardecls), "\n"));
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

// Writes instructions corresponding to a funcall to output.
node* CGfuncall(node* arg_node, info* arg_info) {
    DBUG_ENTER("CGfuncall");

    node *arg = FUNCALL_ARGS(arg_node);

    int arg_amount = 0;
    while (arg) {
      arg_amount++;
      arg = EXPRS_NEXT(arg);
    }

    if (SYMBOLTABLE_PARENT(INFO_CST(arg_info)) && 
        STReq(SYMBOLTABLE_NAME(SYMBOLTABLE_PARENT(INFO_CST(arg_info))), "Global")) {
      write_assembly("\tisrg \n");
    } else {
      write_assembly("\tisrl \n");
    }

    FUNCALL_ARGS(arg_node) = TRAVopt(FUNCALL_ARGS(arg_node), arg_info);
    node* import_node = in_import_table(FUNCALL_FUNDEF(arg_node), INFO_IMP(arg_info));

    if (import_node) {
      write_assembly(STRcatn(3,"\tjsre ", STRitoa(EXTERN_INDEXLEVEL(import_node)), "\n"));
    } else {
      write_assembly(STRcatn(5, "\tjsr ", STRitoa(arg_amount), " ", FUNDEF_NAME(FUNCALL_FUNDEF(arg_node)), "\n"));
    }

    DBUG_RETURN(arg_node);

}

// Writes instrucitons corresponding to if-else statements to output.
extern node *CGifelse (node *arg_node, info *arg_info) {
    DBUG_ENTER("CGifelse");

    IFELSE_COND(arg_node) = TRAVdo(IFELSE_COND(arg_node), arg_info);

    int label1 = INFO_SUM_L(arg_info) + 1;
    int label2 = label1 + 1;
    INFO_SUM_L(arg_info) = INFO_SUM_S(arg_info) + 2;

    write_assembly(STRcatn(3, "\tbranch_f L", STRitoa(label1), "\n"));

    IFELSE_THEN(arg_node) = TRAVopt(IFELSE_THEN(arg_node), arg_info);

    write_assembly(STRcatn(3, "\tjump L", STRitoa(label2), "\n"));

    write_assembly(STRcatn(3, "L", STRitoa(label1), "\n"));

    IFELSE_ELSE(arg_node) = TRAVopt(IFELSE_ELSE(arg_node), arg_info);

    write_assembly(STRcatn(3, "L", STRitoa(label2), "\n"));

    DBUG_RETURN(arg_node);
}

// Writes instructions corresponding to cast statement to output.
extern node *CGcast(node *arg_node, info *arg_info) {
  DBUG_ENTER("CGcast");

  CAST_EXPR(arg_node) = TRAVdo(CAST_EXPR(arg_node), arg_info);

  type old_type = CAST_TYPE_RIGHT(arg_node);
  type new_type = CAST_TYPE_LEFT(arg_node);
  
  if (old_type != T_bool && new_type != T_bool) {
    write_assembly(STRcatn(5, "\t", type_to_char(old_type), "2", type_to_char(new_type), "\n"));
  } else {
    write_assembly("\tbloadc_t\n");
  } 

  DBUG_RETURN(arg_node);
}

// Writes instructions corresponding to dowhile to output.
extern node *CGdowhile(node *arg_node, info *arg_info) {
  DBUG_ENTER("CGdowhile");

  INFO_SUM_L(arg_info) = INFO_SUM_L(arg_info) + 1;

  int whileamount = INFO_SUM_WHILE(arg_info);

  write_assembly(STRcat(STRitoa(whileamount),"_while:\n"));
  DOWHILE_COND(arg_node) = TRAVdo(DOWHILE_COND(arg_node), arg_info);
  write_assembly(STRcatn(3, "\tbranch_f ", STRitoa(whileamount + 1), "_end\n"));
  DOWHILE_BLOCK(arg_node) = TRAVopt(DOWHILE_BLOCK(arg_node), arg_info);


  write_assembly(STRcatn(3,"\tjump ", STRitoa(whileamount), "_while\n"));
  whileamount++;
  write_assembly(STRcat(STRitoa(whileamount), "_end:\n"));
  whileamount++;
  INFO_SUM_WHILE(arg_info) = whileamount;

  DBUG_RETURN(arg_node);
}

// Writes instructions corresponding to assign statement to output.
extern node *CGassign (node *arg_node, info *arg_info) {
    DBUG_ENTER("CGassign");

    if(optimise_assign(arg_node, INFO_CT(arg_info)) == 1) {
      DBUG_RETURN(arg_node);
    }

    ASSIGN_EXPR(arg_node) = TRAVdo(ASSIGN_EXPR(arg_node), arg_info);

    if (ASSIGN_LET(arg_node)) {

      if (get_entry_node(VARLET_DECL(ASSIGN_LET(arg_node)), INFO_GST(arg_info), FALSE)) {
        char *type_char = type_to_char(ASSIGN_TYPE(arg_node));
        int index = SYMBOLTABLEENTRY_INDEXLEVEL(VARLET_DECL(ASSIGN_LET(arg_node)));
        int funamount = functions_amount(INFO_GST(arg_info));

        write_assembly(STRcatn(5, "\t", type_char, "storeg ", STRitoa(index - funamount), "\n"));
      }
      else {
        char *type_char = type_to_char(ASSIGN_TYPE(arg_node));
        int index = SYMBOLTABLEENTRY_INDEXLEVEL(VARLET_DECL(ASSIGN_LET(arg_node)));
        write_assembly(STRcatn(5, "\t", type_char, "store ", STRitoa(index), "\n"));
      }

    } else {
      char *type_char = type_to_char(ASSIGN_TYPE(arg_node));
      int index = SYMBOLTABLEENTRY_INDEXLEVEL(VARLET_DECL(ASSIGN_LET(arg_node)));
      write_assembly(STRcatn(5, "\t", type_char, STRitoa(index), "\n"));
    }

    INFO_SUM_V(arg_info) = INFO_SUM_V(arg_info) + 1;
    INFO_SUM_S(arg_info) = INFO_SUM_S(arg_info) + 1;

    DBUG_RETURN(arg_node);
}

// Writes instructions corresponding to binop expression to output.
node *CGbinop(node* arg_node, info* arg_info) {
    DBUG_ENTER("CGbinop");

    BINOP_LEFT(arg_node) = TRAVdo(BINOP_LEFT(arg_node), arg_info);
    BINOP_RIGHT(arg_node) = TRAVdo(BINOP_RIGHT(arg_node), arg_info);

    write_assembly(STRcatn(4, "\t", type_to_char(BINOP_SUBTYPE(arg_node)), binop_to_char(BINOP_OP(arg_node)), "\n"));

    DBUG_RETURN(arg_node);
}

// Writes instructions corresponding to monop expression to output.
node *CGmonop(node *arg_node, info *arg_info) {
  DBUG_ENTER("CGmonop");

  MONOP_OPERAND(arg_node) = TRAVdo(MONOP_OPERAND(arg_node), arg_info);

  switch(MONOP_TYPE(arg_node)) {
    case T_int:
      write_assembly("\tineg\n");
      break;
    case T_float:
      write_assembly("\tfneg\n");
      break;
    case T_bool:
      write_assembly("\tbnot\n");
      break;
    default:
      break;
  }
  
  DBUG_RETURN(arg_node);
}

// Writes instructions corresponding to return statement to output.
node *CGreturn(node* arg_node, info* arg_info) {
    DBUG_ENTER("CGreturn");

    RETURN_EXPR(arg_node) = TRAVopt(RETURN_EXPR(arg_node), arg_info);

    if (RETURN_EXPR(arg_node)) {
      write_assembly(STRcatn(3, "\t", type_to_char(RETURN_TYPE(arg_node)), "return\n"));

    } else {
      write_assembly("\treturn\n");
    }

    DBUG_RETURN(arg_node);
}

// Writes instructions corresponding to var expression to output.
node *CGvar(node* arg_node, info* arg_info) {
    DBUG_ENTER("CGvar");

    node* st_entry = get_entry_node(VAR_DECL(arg_node), INFO_CST(arg_info), FALSE);

    if (get_entry_node(VAR_DECL(arg_node), INFO_GST(arg_info), FALSE)) {
      int funamount = functions_amount(INFO_GST(arg_info));
      char *type_char = type_to_char(SYMBOLTABLEENTRY_TYPE(VAR_DECL(arg_node)));
      int index = SYMBOLTABLEENTRY_INDEXLEVEL(VAR_DECL(arg_node));
      write_assembly(STRcatn(5, "\t", type_char, "loadg ", STRitoa(index - funamount), "\n"));

    } else if (st_entry == VAR_DECL(arg_node) && SYMBOLTABLEENTRY_INDEXLEVEL(VAR_DECL(arg_node)) > 3) {
      char *type_char = type_to_char(SYMBOLTABLEENTRY_TYPE(VAR_DECL(arg_node)));
      int index = SYMBOLTABLEENTRY_INDEXLEVEL(VAR_DECL(arg_node));
      write_assembly(STRcatn(5, "\t", type_char, "load ", STRitoa(index), "\n"));

    } else if (st_entry == VAR_DECL(arg_node) && SYMBOLTABLEENTRY_INDEXLEVEL(VAR_DECL(arg_node)) <= 3) {
      char* optimised_string = optimise_constant(arg_node);
      write_assembly(STRcatn(4, "\t", type_to_char(SYMBOLTABLEENTRY_TYPE(VAR_DECL(arg_node))), optimised_string, "\n"));
    }

    INFO_SUM_V(arg_info) = INFO_SUM_V(arg_info) + 1;

    DBUG_RETURN(arg_node);
}


// Writes instructions corresponding to num expression to output.
node* CGnum(node* arg_node, info* arg_info) {
    DBUG_ENTER("CGnum");

    node* constant_table = in_table(arg_node, INFO_CT(arg_info));
    if (constant_table) {
      write_assembly(STRcatn(3, "\tiloadc ", STRitoa(CONSTANT_INDEX(constant_table)), "\n"));
    } else {
      char* optimisedCode = optimise_constant(arg_node);
      write_assembly(STRcat(optimisedCode, "\n"));
    }

    INFO_SUM_C(arg_info) = INFO_SUM_C(arg_info) + 1;
    
    DBUG_RETURN(arg_node);
}

// Writes instructions corresponding to float expression to output.
node* CGfloat(node* arg_node, info* arg_info) {
    DBUG_ENTER("CGfloat");

    node* constant_table = in_table(arg_node, INFO_CT(arg_info));
    if (constant_table) {
      write_assembly(STRcatn(3, "\tfloadc ", STRitoa(CONSTANT_INDEX(constant_table)), "\n"));
    } else {
      char* optimisedCode = optimise_constant(arg_node);
      write_assembly(STRcat(optimisedCode, "\n"));
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
