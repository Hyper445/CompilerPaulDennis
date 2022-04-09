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
#include "make_table_helper.h"
#include "code_generation_helper.h"
#include "var_to_assign.h"
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
type get_type(node* expr, info* arg_info);


struct INFO {
  type type;
  node* Symboltable;
};

#define INFO_TYPE(n) ((n)->type)
#define INFO_ST(n) ((n)->Symboltable)

static info *MakeInfo(void) {
  info *result;

  DBUG_ENTER( "MakeInfo");

  result = (info *)MEMmalloc(sizeof(info));
  INFO_TYPE(result) = T_unknown;
  INFO_ST(result) = NULL;
  DBUG_RETURN( result);
}
node *TCprogram(node *arg_node, info* arg_info) {

  DBUG_ENTER("TCprogram");

  INFO_ST(arg_info) = PROGRAM_SYMBOLTABLE(arg_node);
  PROGRAM_DECLS(arg_node) = TRAVopt(PROGRAM_DECLS(arg_node), arg_info); 

  DBUG_RETURN(arg_node);

}

node *TCfundef(node *arg_node, info* arg_info) {

  DBUG_ENTER("TCfundef");
  node* parent_table = INFO_ST(arg_info);
  INFO_ST(arg_info) = FUNDEF_SYMBOLTABLE(arg_node);
  node* symboltable = FUNDEF_SYMBOLTABLE(arg_node);
  
  if (FUNDEF_FUNBODY(arg_node)) {
    node *funbody = FUNDEF_FUNBODY(arg_node);
    node *stmts = FUNBODY_STMTS(funbody);

    while (stmts) {

      if (NODE_TYPE(STMTS_STMT(stmts)) == N_return) {
        break;
      }

      stmts = STMTS_NEXT(stmts);

    }
    if (!stmts && SYMBOLTABLEENTRY_TYPE(get_entry(SYMBOLTABLE_NAME(symboltable), symboltable, TRUE)) != T_void) {
      CTIerrorLine(NODE_LINE(arg_node), "Function expects return!");
    } else if (!stmts && SYMBOLTABLEENTRY_TYPE(
        get_entry(SYMBOLTABLE_NAME(symboltable), symboltable, TRUE)) == T_void) {
      addNodeStatements(TBmakeReturn(NULL), FUNDEF_FUNBODY(arg_node));
    }

  }

  FUNDEF_PARAMS(arg_node) = TRAVopt(FUNDEF_PARAMS(arg_node), arg_info);
  FUNDEF_FUNBODY(arg_node) = TRAVopt(FUNDEF_FUNBODY(arg_node), arg_info);

  INFO_ST(arg_info) = parent_table;



  DBUG_RETURN(arg_node);

}

node *TCbinop (node *arg_node, info *arg_info) {
  
  DBUG_ENTER("TCbinop");

  // Get the left and right expression of the current node
  BINOP_LEFT(arg_node) = TRAVdo(BINOP_LEFT(arg_node), arg_info);
  type left = INFO_TYPE(arg_info);
  BINOP_RIGHT(arg_node) = TRAVdo(BINOP_RIGHT(arg_node), arg_info);
  type right = INFO_TYPE(arg_info);

  BINOP_SUBTYPE(arg_node) = left;

  if(left == T_unknown || left == T_void || right == T_unknown || right == T_void) {
    CTIerrorLine(NODE_LINE(arg_node), "Binary operators cannot be applied to variables with type 'unknown' or 'void'.");
    DBUG_RETURN(arg_node);
  }

  binop operator = BINOP_OP(arg_node);

  if(!(left == right)) {
    CTIerrorLine(NODE_LINE(arg_node),"the '%s' operator cannot be applied to type '%s' and type '%s'. Binary Operators can only be applied to two values of the same type.", binop_to_string(operator), type_to_string(left), type_to_string(right));
  }

  switch (operator) {
    case BO_add:
    case BO_mul:
      INFO_TYPE(arg_info) = left;
      break;
    case BO_div:
    case BO_sub:
      INFO_TYPE(arg_info) = left;
      if(left == T_bool || right == T_bool) {CTIerrorLine(NODE_LINE(arg_node),"the '%s' operator cannot be applied to booleans.");}
      break;
    case BO_mod:
      INFO_TYPE(arg_info) = left;
      if(left != T_int || right != T_int) {CTIerrorLine(NODE_LINE(arg_node),"the modulo operator cannot be used on a '%s' and a '%s'.", type_to_string(left), type_to_string(right));}
      break;
    case BO_lt:
    case BO_le:
    case BO_gt:
    case BO_ge:
      INFO_TYPE(arg_info) = T_bool;
      if(left == T_bool || right == T_bool) {CTIerrorLine(NODE_LINE(arg_node),"the '%s' operator cannot be applied to a boolean.", binop_to_string(operator));}
      break;
    case BO_eq:
    case BO_ne:
      INFO_TYPE(arg_info) = T_bool;
      break;
    case BO_and:
    case BO_or:
      INFO_TYPE(arg_info) = T_bool;
      if(left != T_bool || right != T_bool) {CTIerrorLine(NODE_LINE(arg_node),"the '%s' operator cannot be applied to a '%s' and a '%s'", binop_to_string(operator), type_to_string(left), type_to_string(right));}
      break;
    default:
      CTIerror("unknown operator.");
      INFO_TYPE(arg_info) = T_unknown;
  }

  // Sets the binop type to the correct value.
  BINOP_TYPE(arg_node) = INFO_TYPE(arg_info);

  DBUG_RETURN(arg_node);

}

node *TCmonop (node *arg_node, info *arg_info) {
  DBUG_ENTER("TCmonop");

  MONOP_OPERAND(arg_node) = TRAVdo(MONOP_OPERAND(arg_node), arg_info);
  type type = INFO_TYPE(arg_info);
  monop operator = MONOP_OP(arg_node);

  if(operator == MO_not) {
    INFO_TYPE(arg_info) = T_bool;
    if(type != T_bool) {
      CTIerrorLine(NODE_LINE(arg_node),"operator 'not' cannot be applied to type '%s'", type_to_string(type));
    }
  }
  else if (operator == MO_neg) {
    INFO_TYPE(arg_info) = type;
  }
  else {
    INFO_TYPE(arg_info) = T_unknown;
    CTIerrorLine(NODE_LINE(arg_node),"unknown operator.");
  }

  // Sets the monop type to the correct value.
  MONOP_TYPE(arg_node) = INFO_TYPE(arg_info);

  DBUG_RETURN(arg_node);
}

node *TCcast (node *arg_node, info *arg_info) {
  DBUG_ENTER("TCcast");

  CAST_EXPR(arg_node) = TRAVdo(CAST_EXPR(arg_node), arg_info);
  CAST_TYPE_RIGHT(arg_node) = INFO_TYPE(arg_info);

  INFO_TYPE(arg_info) = CAST_TYPE_LEFT(arg_node);

  DBUG_RETURN(arg_node);
}

node *TCfuncall (node *arg_node, info *arg_info) {
  DBUG_ENTER("TCfuncall");

  FUNCALL_ARGS(arg_node) = TRAVopt(FUNCALL_ARGS(arg_node), arg_info);
  node* symboltable = INFO_ST(arg_info);
  node* fun_entry = get_entry_node(FUNCALL_DECL(arg_node), INFO_ST(arg_info), TRUE);
  node* fundef = NULL;
  if (fun_entry) {
    fundef = SYMBOLTABLEENTRY_FUNDEF(fun_entry);
  }
  node* funcall_params = FUNCALL_ARGS(arg_node);
  node* fun_params = NULL;

  
  if (fun_entry) {
    fun_params = SYMBOLTABLEENTRY_PARAMS(fun_entry);
    INFO_TYPE(arg_info) = SYMBOLTABLEENTRY_TYPE(fun_entry);
  }

  while (fun_params && funcall_params) {

    if (PARAM_TYPE(fun_params) == get_type(EXPRS_EXPR(funcall_params), arg_info)) {
      fun_params = PARAM_NEXT(fun_params);
      funcall_params = EXPRS_NEXT(funcall_params);

    } else {
      
      CTIerror("Types in funcall don't match in actual function!\n");
      break;
    
    }
  }


  if (!fun_params && funcall_params) { 
    CTIerror("Too many arguments!\n");
  }
    
  if (fun_params && !funcall_params) {
    CTIerror("Too few arguments!\n");
  }

  if (!symboltable) {
    CTIerror("No function named %s! \n", FUNCALL_NAME(arg_node));
  }

  FUNCALL_FUNDEF(arg_node) = fundef;

  DBUG_RETURN(arg_node);
}

node* TCreturn (node* arg_node, info* arg_info) {

  DBUG_ENTER("TCreturn");

  RETURN_EXPR(arg_node) = TRAVopt(RETURN_EXPR(arg_node), arg_info);
  type returnType = INFO_TYPE(arg_info);
  printf("%s\n", SYMBOLTABLE_NAME(INFO_ST(arg_info)));

  node* test = TBmakeReturn(NULL);
  
  if (RETURN_EXPR(test)) {
    printf("test\n");
    if (NODE_TYPE(RETURN_EXPR(test)) == N_num) {
      printf("%d\n", RETURN_EXPR(test) == NULL);
    }
  }
  if (RETURN_EXPR(arg_node)) {
    if (NODE_TYPE(RETURN_EXPR(arg_node)) == N_num) {
      printf("%d\n", RETURN_EXPR(arg_node) == NULL);
    }

  }

  // Check if the expr type matches the fundef type
  node* fundefEntry = get_entry(SYMBOLTABLE_NAME(INFO_ST(arg_info)), INFO_ST(arg_info), TRUE);

  type fundefType = SYMBOLTABLEENTRY_TYPE(fundefEntry);

  if (fundefType != returnType && fundefType != T_void) {

    CTIerrorLine(NODE_LINE(arg_node),"function '%s' expects '%s' type.", SYMBOLTABLE_NAME(INFO_ST(arg_info)), type_to_string(fundefType));

  } 
  else if (fundefType == T_void && RETURN_EXPR(arg_node)) {

    CTIerrorLine(NODE_LINE(arg_node),"function '%s' doesn't expect a return.", SYMBOLTABLE_NAME(INFO_ST(arg_info)));

  }

  RETURN_TYPE(arg_node) = returnType;

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
  ASSIGN_TYPE(arg_node) = left;

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

node *TCglobdef(node *arg_node, info *arg_info) {
  DBUG_ENTER("TCglobdef");

  type left = GLOBDEF_TYPE(arg_node);
  GLOBDEF_INIT(arg_node) = TRAVopt(GLOBDEF_INIT(arg_node), arg_info);
  if(GLOBDEF_INIT(arg_node) != NULL) {
    type right = INFO_TYPE(arg_info);
    if (left != right) {
      CTIerrorLine(NODE_LINE(arg_node),"type '%s' does not match type '%s' in assign operation.", type_to_string(left), type_to_string(right));
    }
  }

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
    CTIerrorLine(NODE_LINE(arg_node), "variable %s is not declared", VAR_NAME(arg_node));
  }

  DBUG_RETURN(arg_node);
}

node *TCvarlet(node *arg_node, info *arg_info) {
  DBUG_ENTER("TCvarlet");

  node *entry = VARLET_DECL(arg_node);

  if(entry != NULL) {
    INFO_TYPE(arg_info) = SYMBOLTABLEENTRY_TYPE(entry);
  }
  else {
    INFO_TYPE(arg_info) = T_unknown;
    CTIerrorLine(NODE_LINE(arg_node), "variable %s is not declared", VARLET_NAME(arg_node));
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


type get_type(node* expr, info* arg_info) {

  switch (NODE_TYPE(expr)) {

    case N_binop:
      return BINOP_TYPE(expr);

    case N_monop:
      return MONOP_TYPE(expr);

    case N_funcall:
      return SYMBOLTABLEENTRY_TYPE(get_entry_node(FUNCALL_DECL(expr), INFO_ST(arg_info), TRUE));

    case N_cast:
      return CAST_TYPE_LEFT(expr);

    case N_var:
      return SYMBOLTABLEENTRY_TYPE(get_entry(STRcpy(VAR_NAME(expr)), INFO_ST(arg_info), FALSE));

    case N_num:
      return T_int;

    case N_float:
      return T_float;

    case N_bool:
      return T_bool;
    
    default:
      return T_unknown;

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
      return "less than";
    case BO_le:
      return "less or equal than";
    case BO_gt: 
      return "greater than";
    case BO_ge:
      return "greater or equal than";
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