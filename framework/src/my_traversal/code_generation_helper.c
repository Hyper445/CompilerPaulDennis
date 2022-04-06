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
        
        if (!SYMBOLTABLEENTRY_ISFUNCTION(current_entry)) { 
            
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
      printf("1\n");
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
      printf("%d = indexlevel\n", SYMBOLTABLEENTRY_INDEXLEVEL(VAR_DECL(arg_node)));
      break;

    default:
      CTIerror("unknown node type (code_generation_helper)");
      break;
  }

  return NULL;
}

int optimise_assign(node *arg_node, node *constant_table) {
  node *expr = ASSIGN_EXPR(arg_node);
  if(NODE_TYPE(expr) == N_binop && BINOP_OP(expr) == BO_add) {
    // Expr is a addition.
    if(NODE_TYPE(BINOP_LEFT(expr)) == N_var && STReq(VAR_NAME(BINOP_LEFT(expr)), VARLET_NAME(ASSIGN_LET(arg_node)))) {
      // The addition binop has a var as its left child, the var matches the varlet of the assign node.
      if(NODE_TYPE(BINOP_RIGHT(expr)) == N_num) {
        // The right child of the binop is a num.
        int index_var = SYMBOLTABLEENTRY_INDEXLEVEL(VAR_DECL(BINOP_LEFT(expr)));
        if(NUM_VALUE(BINOP_RIGHT(expr)) == 1) {
          printf("\tiinc_1 %d\n", index_var);
          return true;
        }
        else {
          node *constant = in_table(BINOP_RIGHT(expr), constant_table);
          printf("\tiinc %d %d\n", index_var, CONSTANT_INDEX(constant_table));
          return true;
        }
      }
      else {
        // The right child of the binop is not a num.
        return false;
      }
    } else if (NODE_TYPE(BINOP_RIGHT(expr)) == N_var && STReq(VAR_NAME(BINOP_RIGHT(expr)), VARLET_NAME(ASSIGN_LET(arg_node)))) {
      // The binop has a var as its right child, the var matches the varlet of the assign node.
      return true;
    } else {
      // the binop has no var as its child.
      return false;
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

//TODO: monop to char