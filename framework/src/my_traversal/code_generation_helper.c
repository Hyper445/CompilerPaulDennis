#include "code_generation.h"
#include "make_table_helper.h"
#include "code_generation_helper.h"
#include "print.h"
#include "stdbool.h"

#include "stdlib.h"
#include "lookup_table.h"
#include "types.h"
#include "tree_basic.h"
#include "traverse.h"
#include "dbug.h"
#include "str.h"
#include "globals.h"
#include "stdio.h"

#include "memory.h"
#include "ctinfo.h"


void print_funs(node* symbolTable) {

    node* current_entry = SYMBOLTABLE_ENTRIES(symbolTable);
    while (current_entry) {

        if (SYMBOLTABLEENTRY_ISFUNCTION(current_entry)) {
            //.exportfun "__init" void __init
            char *name = SYMBOLTABLEENTRY_NAME(current_entry);
            char *type = type_to_string(SYMBOLTABLEENTRY_TYPE(current_entry));
            write_assembly(STRcatn(7,".exportfun \"", name, "\" ", type, " ", name, "\n"));
            //printf(".exportfun \"%s\" %s %s\n", SYMBOLTABLEENTRY_NAME(current_entry), 
            //    type_to_string(SYMBOLTABLEENTRY_TYPE(current_entry)), SYMBOLTABLEENTRY_NAME(current_entry));
        
        }
        current_entry = SYMBOLTABLEENTRY_NEXT(current_entry);
    }
}

void print_globals(node* symbolTable) {

    node* current_entry = SYMBOLTABLE_ENTRIES(symbolTable);
    while (current_entry) {
        
        if (!SYMBOLTABLEENTRY_ISFUNCTION(current_entry)) { 
            write_assembly(STRcatn(3, ".global ", type_to_string(SYMBOLTABLEENTRY_TYPE(current_entry)), "\n"));
            //printf(".global %s\n", type_to_string(SYMBOLTABLEENTRY_TYPE(current_entry))); 
        }
        current_entry = SYMBOLTABLEENTRY_NEXT(current_entry);
    }
}



void print_constants(node* constant) {

    while (constant) {

      switch(NODE_TYPE(CONSTANT_VALUE(constant))) {
        case N_float:
          write_assembly(STRcatn(3, ".const float ", STRitoa(FLOAT_VALUE(CONSTANT_VALUE(constant))), "\n"));
          printf(".const float %f\n", FLOAT_VALUE(CONSTANT_VALUE(constant)));
          break;
        case N_num:
          write_assembly(STRcatn(3, ".const int ", STRitoa(NUM_VALUE(CONSTANT_VALUE(constant))), "\n"));
          printf(".const int %d\n", NUM_VALUE(CONSTANT_VALUE(constant)));
          break;
        default:
          CTIerror("unknown type (code_generation_helper)");
          break;

      }
      constant = CONSTANT_NEXT(constant);

    }


}

node* in_table(node* value_node, node* constant_table) {

  while (constant_table) {
    if (NODE_TYPE(CONSTANT_VALUE(constant_table)) == NODE_TYPE(value_node)) {
      
      switch (NODE_TYPE(value_node)) {

        case N_float:
          if (FLOAT_VALUE(CONSTANT_VALUE(constant_table)) == FLOAT_VALUE(value_node)) {
            return (constant_table);
          }
          break;

        case N_num:

          if (NUM_VALUE(CONSTANT_VALUE(constant_table)) == NUM_VALUE(value_node)) {              
            return (constant_table);
          }
          break;

        default:
          break;

      }

    }
    constant_table = CONSTANT_NEXT(constant_table);

  }
  return NULL;

}

char* optimise_constant(node* arg_node) {

  // If constant isn't in the table, it is one of the optimised numbers
  switch(NODE_TYPE(arg_node)) {
    case N_num:
      if (NUM_VALUE(arg_node) == -1) {
        return ("\tiloadc_m1");
      } else if (NUM_VALUE(arg_node) == 0) {
        return ("\tiloadc_0");
      } else if (NUM_VALUE(arg_node) == 1) {
        return ("\tiloadc_1");
      }
      break;

    case N_float:
      if (FLOAT_VALUE(arg_node) == 0.0) {
        return ("\tfloadc_0");
      } else if (FLOAT_VALUE(arg_node) == 1.0) {
        return ("\tfloadc_1");
      }
      break;

    case N_var:
      if (SYMBOLTABLEENTRY_INDEXLEVEL(VAR_DECL(arg_node)) == 0) {
        return ("load_0");
      } else if (SYMBOLTABLEENTRY_INDEXLEVEL(VAR_DECL(arg_node)) == 1) {
        return ("load_1");
      } else if (SYMBOLTABLEENTRY_INDEXLEVEL(VAR_DECL(arg_node)) == 2) {
        return ("load_2");
      } else if (SYMBOLTABLEENTRY_INDEXLEVEL(VAR_DECL(arg_node)) == 3) {
        return ("load_3");
      }
      break;

    default:
      CTIerror("unknown node type (code_generation_helper)");
      break;
  }

  return NULL;
}

int optimise_assign(node *arg_node, node *constant_table) {
  node *expr = ASSIGN_EXPR(arg_node);

  if(NODE_TYPE(expr) == N_binop) {

    // gets the operation that should be printed.
    char *instruction;
    switch(BINOP_OP(expr)){
      case BO_add:
        instruction = "iinc";
        break;
      case BO_sub:
        instruction = "idec";
        break;
      default:
        return false;
    }

    // Expr is a addition or substraction. get the var and varlet.
    node *varlet = ASSIGN_LET(arg_node);
    node *var;
    node *constant;
    if(NODE_TYPE(BINOP_LEFT(expr)) == N_var && STReq(VAR_NAME(BINOP_LEFT(expr)), VARLET_NAME(varlet))) {
      var = BINOP_LEFT(expr);
      constant = BINOP_RIGHT(expr);
    }
    else if(NODE_TYPE(BINOP_RIGHT(expr)) == N_var && STReq(VAR_NAME(BINOP_RIGHT(expr)), VARLET_NAME(varlet))){
      var = BINOP_RIGHT(expr);
      constant = BINOP_LEFT(expr);
    } else {
      return false;
    }

    // Exit optimalisation if constant is not a num.
    if(NODE_TYPE(constant) != N_num) {
      return false;
    }

    int index_var = SYMBOLTABLEENTRY_INDEXLEVEL(VAR_DECL(var));
    if(NUM_VALUE(constant) == 1) {
      write_assembly(STRcatn(5, "\t", instruction, "_1 ", STRitoa(index_var), "\n"));
      //printf("\t%s_1 %d\n", instruction, index_var);
      return true;
    }
    else {
      //node *constant_in_table = in_table(constant, constant_table);
      write_assembly(STRcatn(7, "\t", instruction, " ", STRitoa(index_var), " ",STRitoa(CONSTANT_INDEX(constant_table)), "\n"));
      //printf("\t%s %d %d\n", instruction, index_var, CONSTANT_INDEX(constant_table));
      return true;
    }
  }
  else {
    // right child of assign is not a binop.
    return false;
  }
}

// Helper function. Converts a type to a string.
char* type_to_string(int type) {
  switch(type) {
    case T_bool:
      return "boolean";
    case T_float:
      return "float";
    case T_int:
      return "int";
    case T_void:
      return "void";
    default:
      return "unknown";
  }
}


char* type_to_char(int type) {

  switch(type) {
    case 0:
      return ("");
    case 1 :
      return ("b");
    case 2 :
      return("i");
    case 3 :
      return("f");
    default:
      CTIerror("undefined type");
      return("");
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
      return("");
    // case BO_and :
    //   return ("and");
    // case BO_or :
    //   return("or");
  }
}

void write_assembly(char *assembly) {
  if(global.outfile != NULL) {
    FILE *file = fopen(global.outfile, "a");
    fputs(assembly, file);
    fclose(file);
  }
  else {
    printf("%s", assembly);
  }
}