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


void print_funs(node* symbolTable) {

    node* current_entry = SYMBOLTABLE_ENTRIES(symbolTable);
    while (current_entry) {

        if (SYMBOLTABLEENTRY_PARAMS(current_entry)) {
            //.exportfun "__init" void __init
            printf(".exportfun \"%s\" %s %s\n", SYMBOLTABLEENTRY_NAME(current_entry), 
                type_to_string(SYMBOLTABLEENTRY_TYPE(current_entry)), SYMBOLTABLEENTRY_NAME(current_entry));
        
        }
        current_entry = SYMBOLTABLEENTRY_NEXT(current_entry);
    }
}

void print_globals(node* symbolTable) {

    node* current_entry = SYMBOLTABLE_ENTRIES(symbolTable);
    while (current_entry) {
        
        if (!SYMBOLTABLEENTRY_PARAMS(current_entry)) { 
            
            printf(".global %s\n", type_to_string(SYMBOLTABLEENTRY_TYPE(current_entry))); 
        }
        current_entry = SYMBOLTABLEENTRY_NEXT(current_entry);
    }
}



void print_constants(node* constant) {

    while (constant) {

      switch(NODE_TYPE(CONSTANT_VALUE(constant))) {
        case N_float:
          printf(".constant float %f\n", FLOAT_VALUE(CONSTANT_VALUE(constant)));
          break;
        case N_num:
          printf(".constant int %d\n", NUM_VALUE(CONSTANT_VALUE(constant)));
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

char* optimise(node* arg_node) {

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
      printf("1\n");
      if (FLOAT_VALUE(arg_node) == 0.0) {
        return ("\tfloadc_0");
      } else if (FLOAT_VALUE(arg_node) == 1.0) {
        return ("\tfloadc_1");
      }
      break;

    case N_var:
      if (SYMBOLTABLEENTRY_INDEXLEVEL(VAR_DECL(arg_node)) == 0) {
        return ("\tload_0");
      } else if (SYMBOLTABLEENTRY_INDEXLEVEL(VAR_DECL(arg_node)) == 1) {
        return ("\tload_1");
      } else if (SYMBOLTABLEENTRY_INDEXLEVEL(VAR_DECL(arg_node)) == 2) {
        return ("\tload_2");
      } else if (SYMBOLTABLEENTRY_INDEXLEVEL(VAR_DECL(arg_node)) == 3) {
        return ("\tload_3");
      }
      break;

    default:
      CTIerror("unknown node type (code_generation_helper)");
      break;
  }

  return NULL;
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

//TODO: monop to char