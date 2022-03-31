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

node* in_table(node* value_node, node* constant_table) {

  if (constant_table) {

    while (constant_table) {

      if (NODE_TYPE(CONSTANT_VALUE(constant_table)) == NODE_TYPE(value_node))
        
        switch (NODE_TYPE(value_node)) {

          case N_float:
            if (FLOAT_VALUE(CONSTANT_VALUE(constant_table)) == FLOAT_VALUE(value_node)) {
              return (constant_table);
            }

          case N_num:

            if (NUM_VALUE(CONSTANT_VALUE(constant_table)) == NUM_VALUE(value_node)) {              
              return (constant_table);
            }

          default:
            break;

        }

      constant_table = CONSTANT_NEXT(constant_table);

    }
  }

  return NULL;

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