/*****************************************************************************
 *
 * Module: type checker
 *
 * Prefix: EST
 *
 * Description:
 *
 * This module type checks the traversal tree.
 *
 *****************************************************************************/

#include "make_table.h"

#include "lookup_table.h"
#include "types.h"
#include "tree_basic.h"
#include "traverse.h"
#include "dbug.h"
#include "str.h"

#include "memory.h"
#include "ctinfo.h"

char* type_to_string(int type);
char* binop_to_string(int operator);
char* monop_to_string(int operator);

struct INFO {
  type type;
};

#define INFO_TYPE(n) ((n)->type)

static info *MakeInfo(void) {
  info *result;

  DBUG_ENTER( "MakeInfo");

  result = (info *)MEMmalloc(sizeof(info));
  INFO_TYPE(result) = T_unknown;
  DBUG_RETURN( result);
}

node *TCbinop (node *arg_node, info *arg_info) {
  
  DBUG_ENTER("TCbinop");

  // Get the left and right expression of the current node
  BINOP_LEFT(arg_node) = TRAVdo(BINOP_LEFT(arg_node), arg_info);
  type left = INFO_TYPE(arg_info);
  BINOP_RIGHT(arg_node) = TRAVdo(BINOP_RIGHT(arg_node), arg_info);
  type right = INFO_TYPE(arg_info);

  if(left == T_unknown || left == T_void || right == T_unknown || right == T_void) {
    CTIerrorLine(NODE_LINE(arg_node), "Binary operators cannot be applied to variables with type 'unknown' or 'void'.");
    DBUG_RETURN(arg_node);
  }

  binop operator = BINOP_OP(arg_node);

  switch (operator) {
    case BO_add:
    case BO_mul:
      INFO_TYPE(arg_info) = left;
      if(!(left == right)) {CTIerrorLine(NODE_LINE(arg_node),"the '%s' operator cannot be applied to type '%s' and type '%s'.", binop_to_string(operator), type_to_string(left), type_to_string(right));}
      break;
    case BO_div:
    case BO_sub:
      INFO_TYPE(arg_info) = left;
      if(left == T_bool || right == T_bool) {CTIerrorLine(NODE_LINE(arg_node),"the '%s' operator cannot be applied to booleans.");}
      break;
    case BO_mod:
      INFO_TYPE(arg_info) = left;
      if(left != T_int || right != T_int) {CTIerrorLine(NODE_LINE(arg_node),"the modulo operator cannot be used on a '%s' and a '%s'.", type_to_string(left), type_to_string(right));}
    case BO_lt:
    case BO_le:
    case BO_gt:
    case BO_ge:
      INFO_TYPE(arg_info) = T_bool;
      if(left == T_bool || right == T_bool) {CTIerrorLine(NODE_LINE(arg_node),"the '%s' operator cannot be applied to a boolean.", binop_to_string(operator));}
    case BO_eq:
    case BO_ne:
      INFO_TYPE(arg_info) = T_bool;
    case BO_and:
    case BO_or:
      INFO_TYPE(arg_info) = T_bool;
      if(left != T_bool || right != T_bool) {CTIerrorLine(NODE_LINE(arg_node),"the '%s' operator cannot be applied to a '%s' and a '%s'", binop_to_string(operator), type_to_string(left), type_to_string(right));}
      break;
    default:
      CTIerror("unknown operator.");
      INFO_TYPE(arg_info) = T_unknown;
  }

  DBUG_RETURN(arg_node);

}

node *TCmonop (node *arg_node, info *arg_info) {
  DBUG_ENTER("TCmonop");

  MONOP_OPERAND(arg_node) = TRAVdo(MONOP_OPERAND(arg_node), arg_info);
  type type =  INFO_TYPE(arg_info);
  monop operator = MONOP_OP(arg_node);

  if(operator == MO_not) {
    INFO_TYPE(arg_info) = T_bool;
    if(type != T_bool) {
      CTIerrorLine(NODE_LINE(arg_node),"operator 'not' cannot be applied to type '%s'", type_to_string(type));
    }
  }
  else if (operator == MO_neg) {
    INFO_TYPE(arg_info) = type;
    if(type == T_bool) {
      CTIerrorLine(NODE_LINE(arg_node),"monop operator '-' cannot be applied to type boolean.");
    }
  }
  else {
    INFO_TYPE(arg_info) = T_unknown;
    CTIerrorLine(NODE_LINE(arg_node),"unknown operator.");
  }

  DBUG_RETURN(arg_node);
}

node *TCcast (node *arg_node, info *arg_info) {
  DBUG_ENTER("TCcast");

  CAST_EXPR(arg_node) = TRAVdo(CAST_EXPR(arg_node), arg_info);

  INFO_TYPE(arg_info) = CAST_TYPE(arg_node);

  DBUG_RETURN(arg_node);
}

node *TCfuncall (node *arg_node, info *arg_info) {
  DBUG_ENTER("TCfuncall");
  
  FUNCALL_ARGS(arg_node) = TRAVopt(FUNCALL_ARGS(arg_node), arg_info);

  //node *arguments = FUNCALL_ARGS(arg_node);
  //node *fun_declaration = FUNCALL_DECL(arg_node);
  
  // TODO

  DBUG_RETURN(arg_node);
}



node *TCassign (node *arg_node, info *arg_info) {
  DBUG_ENTER("TCassign");

  ASSIGN_LET(arg_node) = TRAVopt(ASSIGN_LET(arg_node), arg_info);
  type left = INFO_TYPE(arg_info);
  ASSIGN_EXPR(arg_node) = TRAVdo(ASSIGN_EXPR(arg_node), arg_info);
  type right = INFO_TYPE(arg_info);

  if (left != right) {
    CTIerrorLine(NODE_LINE(arg_node),"type '%s' does not match type '%s' in assign operation.", type_to_string(left), type_to_string(right));
  }

  DBUG_RETURN(arg_node);
}

node *TCvardecl(node *arg_node, info *arg_info) {
  DBUG_ENTER("TCvardecl");

  if (VARDECL_INIT(arg_node)) {
    VARDECL_INIT(arg_node) = TRAVopt(VARDECL_INIT(arg_node), arg_info);
    type right = INFO_TYPE(arg_info);
    type left = VARDECL_TYPE(arg_node);

    if (left != right) {
      CTIerrorLine(NODE_LINE(arg_node), "type '%s' does not match type '%s' in vardecl operation.", type_to_string(left), type_to_string(right));
      
    }
  }
  
  VARDECL_NEXT(arg_node) = TRAVopt(VARDECL_NEXT(arg_node), arg_info);

  DBUG_RETURN(arg_node);
}


node *TCnum(node *arg_node, info *arg_info) {
  DBUG_ENTER("TCnum");

  INFO_TYPE(arg_info) = T_int;

  DBUG_RETURN(arg_node);
}

node *TCfloat(node *arg_node, info *arg_info) {
  DBUG_ENTER("TCfloat");

  INFO_TYPE(arg_info) = T_float;

  DBUG_RETURN(arg_node);
}


node *TCbool(node *arg_node, info *arg_info) {
  DBUG_ENTER("TCbool");

  INFO_TYPE(arg_info) = T_bool;

  DBUG_RETURN(arg_node);
}

node *TCvar(node *arg_node, info *arg_info) {
  DBUG_ENTER("TCvar");

  node *entry = VAR_DECL(arg_node);

  if(entry != NULL) {
    INFO_TYPE(arg_info) = SYMBOLTABLEENTRY_TYPE(entry);
  }
  else {
    INFO_TYPE(arg_info) = T_unknown;
    CTIerror("variable %s is not declared", VAR_NAME(arg_node));
  }

  DBUG_RETURN(arg_node);
}

node *TCvarlet(node *arg_node, info *arg_info) {
  DBUG_ENTER("TCvarlet");

  printf("TCvarlet is being executed\n");

  node *entry = VARLET_DECL(arg_node);

  if(entry != NULL) {
    INFO_TYPE(arg_info) = SYMBOLTABLEENTRY_TYPE(entry);
  }
  else {
    INFO_TYPE(arg_info) = T_unknown;
    CTIerror("variable %s is not declared", VARLET_NAME(arg_node));
  }

  DBUG_RETURN(arg_node);
}

/*
 * Traversal start function
 */

node *TCdoTypeCheck( node *syntaxtree)
{
  info *arg_info;
  DBUG_ENTER("TCdoTypeCheck");
  arg_info = MakeInfo();

  TRAVpush( TR_tc);
  syntaxtree = TRAVdo( syntaxtree, arg_info);
  TRAVpop();

  DBUG_RETURN( syntaxtree);
}

// Helper function. Converts a type to a string.
char* type_to_string(int type) {
  switch(type) {
    case T_bool:
      return "boolean";
    case T_float:
      return "float";
    case T_int:
      return "integer";
    case T_void:
      return "void";
    default:
      return "unknown";
  }
}

// Helper function. Converts an operator to a string.
char* binop_to_string(int operator) {
  switch(operator) {
    case BO_add:
      return "addition";
    case BO_sub:
      return "substraction";
    case BO_mul:
      return "multiplication";
    case BO_div:
      return "division";
    case BO_mod:
      return "modulo";
    case BO_lt:
      return "less then";
    case BO_le:
      return "less or equal then";
    case BO_gt: 
      return "greater then";
    case BO_ge:
      return "greater or equal then";
    case BO_eq:
      return "equality";
    case BO_ne:
      return "not equal";
    case BO_and:
      return "and";
    case BO_or:
      return "or";
    default:
      return "unknown";
  }
}

// Helper function. Converts a monop operator to a string.
char* monop_to_string(int operator) {
  switch(operator) {
    case MO_not:
      return "not";
    case MO_neg:
      return "-";
    default:
      return "unknown";
  }
}