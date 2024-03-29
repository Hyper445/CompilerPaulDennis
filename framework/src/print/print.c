/**
 * @file print.c
 *
 * Functions needed by print traversal.
 *
 */

/**
 * @defgroup print Print Functions.
 *
 * Functions needed by print traversal.
 *
 * @{
 */

#include "lookup_table.h"
#include "print.h"
#include "traverse.h"
#include "tree_basic.h"
#include "dbug.h"
#include "memory.h"
#include "globals.h"


void print_type(int type);

/*
 * INFO structure
 */
struct INFO {
  bool firsterror;
  int indentation;
  char* indentationTabs;
};

#define INFO_FIRSTERROR(n) ((n)->firsterror)
#define INFO_INDENTATION(n) ((n)->indentation)
#define INFO_TABS(n) ((n)->indentationTabs)

static info *MakeInfo()
{
  info *result;
  
  result = MEMmalloc(sizeof(info));

  INFO_FIRSTERROR(result) = FALSE;
  INFO_INDENTATION(result) = 0;
  INFO_TABS(result) = "    ";
  
  return result;
}


static info *FreeInfo( info *info)
{
  info = MEMfree( info);

  return info;
}

extern node *PRTsymboltable (node * arg_node, info * arg_info){return arg_node;}
extern node *PRTconstant (node * arg_node, info * arg_info){return arg_node;}
extern node *PRTexport (node * arg_node, info * arg_info){return arg_node;}
extern node *PRTextern (node * arg_node, info * arg_info){return arg_node;}

extern node *PRTdeclarations (node * arg_node, info * arg_info){return arg_node;}

extern node *PRTexprs (node * arg_node, info * arg_info){
  DBUG_ENTER ("PRTexprs");

  EXPRS_EXPR( arg_node) = TRAVdo( EXPRS_EXPR(arg_node), arg_info);
  EXPRS_NEXT ( arg_node) = TRAVopt (EXPRS_NEXT(arg_node), arg_info);

  DBUG_RETURN(arg_node);
}
extern node *PRTarrexpr (node * arg_node, info * arg_info){return arg_node;}

extern node *PRTcondexpr (node * arg_node, info * arg_info){
  DBUG_ENTER ("PRTexprstmt");
  
  CONDEXPR_PRED(arg_node) = TRAVopt(CONDEXPR_PRED(arg_node), arg_info);
  printf("?");
  CONDEXPR_THEN(arg_node) = TRAVopt(CONDEXPR_THEN(arg_node), arg_info);
  printf(":");
  CONDEXPR_ELSE(arg_node) = TRAVopt(CONDEXPR_ELSE(arg_node), arg_info);

  
  DBUG_RETURN(arg_node);
}


extern node *PRTexprstmt (node * arg_node, info * arg_info){
  DBUG_ENTER ("PRTexprstmt");

  EXPRSTMT_EXPR( arg_node) = TRAVdo( EXPRSTMT_EXPR( arg_node), arg_info);
  
  DBUG_RETURN(arg_node);
  }

extern node *PRTfuncall (node * arg_node, info * arg_info){
  DBUG_ENTER ("PRTfuncall");
  printf("%s(", FUNCALL_NAME(arg_node));

  FUNCALL_ARGS( arg_node) = TRAVopt( FUNCALL_ARGS( arg_node), arg_info);

  printf(");");

  DBUG_RETURN(arg_node);
  }

extern node *PRTcast (node * arg_node, info * arg_info){
  DBUG_ENTER ("PRTcast");

  printf("(");
  print_type(CAST_TYPE_LEFT(arg_node));
  printf(") ");

  CAST_EXPR(arg_node) = TRAVdo( CAST_EXPR(arg_node), arg_info);

  printf("\n");

  DBUG_RETURN(arg_node);
  }

extern node *PRTdowhile (node * arg_node, info * arg_info){
  DBUG_ENTER ("PRTdowhile");
  printf("do{\n");
  DOWHILE_BLOCK( arg_node) = TRAVopt( DOWHILE_BLOCK(arg_node), arg_info);
  printf("} while (");
  DOWHILE_COND( arg_node) = TRAVopt( DOWHILE_COND(arg_node), arg_info);
  printf(")\n");
  DBUG_RETURN(arg_node);
  }

extern node *PRTglobdecl (node * arg_node, info * arg_info){
  DBUG_ENTER ("PRTglobdecl");

  printf("extern ");
  print_type(GLOBDECL_TYPE(arg_node));
  printf("%s;\n", GLOBDECL_NAME(arg_node));

  GLOBDECL_DIMS(arg_node) = TRAVopt( GLOBDECL_DIMS( arg_node), arg_info);

  DBUG_RETURN( arg_node);
  }  

extern node *PRTglobdef (node * arg_node, info * arg_info){
  DBUG_ENTER ("PRTglobdef");

  print_type(GLOBDEF_TYPE(arg_node));
  printf("%s", GLOBDEF_NAME(arg_node));

  if (GLOBDEF_INIT(arg_node)) {
    printf(" =");
    GLOBDEF_INIT( arg_node) = TRAVopt( GLOBDEF_INIT( arg_node), arg_info);
  }

  printf(";\n");

  GLOBDEF_DIMS ( arg_node) = TRAVopt( GLOBDEF_DIMS( arg_node), arg_info);
  
  DBUG_RETURN( arg_node);
}

extern node *PRTmonop (node * arg_node, info * arg_info){
  DBUG_ENTER ("PRTmonop");

  switch (MONOP_OP(arg_node)) {
    case 0 :
      printf("!");
      break;
    case 1 :
      printf("-");
      break;
    case 2 :
      printf("unknown");
      break;
  }

  MONOP_OPERAND( arg_node) = TRAVdo( MONOP_OPERAND(arg_node), arg_info);

  DBUG_RETURN(arg_node);
  }

extern node *PRTwhile (node * arg_node, info * arg_info){
  DBUG_ENTER ("PRTwhile");
  printf("while(");
  WHILE_COND( arg_node) = TRAVopt( WHILE_COND(arg_node), arg_info);
  printf(") {\n");
  WHILE_BLOCK( arg_node) = TRAVopt( WHILE_BLOCK(arg_node), arg_info);
  printf("}");
  DBUG_RETURN(arg_node);
  }

extern node *PRTfor (node * arg_node, info * arg_info){
  DBUG_ENTER ("PRTfor");

  printf("for(int %s", FOR_LOOPVAR(arg_node));
  FOR_START( arg_node) = TRAVdo( FOR_START(arg_node), arg_info);
  printf(", ");
  FOR_STOP( arg_node) = TRAVdo( FOR_STOP(arg_node), arg_info);
  printf(", ");
  FOR_STEP( arg_node) = TRAVopt( FOR_STEP(arg_node), arg_info);
  printf(" ){\n");
  FOR_BLOCK( arg_node) = TRAVopt( FOR_BLOCK(arg_node), arg_info);
  printf("}\n");
  DBUG_RETURN(arg_node);
  }

extern node *PRTprogram (node * arg_node, info * arg_info)
{
  DBUG_ENTER ("PRTprogram");


  PROGRAM_DECLS( arg_node) = TRAVdo( PROGRAM_DECLS( arg_node), arg_info);
  
  DBUG_RETURN(arg_node);
}

extern node *PRTdecls (node * arg_node, info * arg_info)
{
  DBUG_ENTER ("PRTdecls");

  DECLS_DECL( arg_node) = TRAVdo( DECLS_DECL( arg_node), arg_info);
  
  DECLS_NEXT( arg_node) = TRAVopt( DECLS_NEXT( arg_node), arg_info);

  DBUG_RETURN(arg_node);
}

extern node *PRTfundef (node * arg_node, info * arg_info)
{

  DBUG_ENTER("PRTfundef");

  print_type(FUNDEF_TYPE(arg_node));

  printf("%s (", FUNDEF_NAME(arg_node));
  
  FUNDEF_PARAMS( arg_node) = TRAVopt( FUNDEF_PARAMS( arg_node), arg_info);

  printf(") {\n");

  printf("%s", INFO_TABS(arg_info));
  FUNDEF_FUNBODY( arg_node) = TRAVopt( FUNDEF_FUNBODY( arg_node), arg_info);
  
  printf("}\n\n");


  DBUG_RETURN( arg_node);

}

extern node *PRTparam (node * arg_node, info * arg_info)
{

  print_type(PARAM_TYPE(arg_node));
  printf("%s", PARAM_NAME(arg_node));
  PARAM_DIMS( arg_node) = TRAVopt(PARAM_DIMS(arg_node), arg_info);

  if(PARAM_NEXT( arg_node) != NULL) {
    printf(", ");
  }
  PARAM_NEXT( arg_node) = TRAVopt(PARAM_NEXT(arg_node), arg_info);

  // printf("%s, %s", PARAM_TYPE(arg_node), PARAM_NAME(arg_node));

  return arg_node;

}

extern node *PRTids (node * arg_node, info * arg_info)
{

  // IDS_NEXT(arg_node) = TRAVopt(IDS_NEXT(arg_node), arg_info);

  // printf("%s", IDS_NAME(arg_node));

  return arg_node;

}


extern node *PRTfunbody (node * arg_node, info * arg_info)
{
  DBUG_ENTER ("PRTfunbody");
  
  FUNBODY_VARDECLS( arg_node) = TRAVopt( FUNBODY_VARDECLS( arg_node), arg_info);

  FUNBODY_LOCALFUNDEFS( arg_node) = TRAVopt( FUNBODY_LOCALFUNDEFS( arg_node), arg_info);

  FUNBODY_STMTS( arg_node) = TRAVopt( FUNBODY_STMTS( arg_node), arg_info);

  printf("\n");

  DBUG_RETURN(arg_node);

}

extern node *PRTfundefs (node * arg_node, info * arg_info) 
{

  DBUG_ENTER("PRTfundefs");

  FUNDEFS_FUNDEF( arg_node) = TRAVdo(FUNDEFS_FUNDEF(arg_node), arg_info);

  FUNDEFS_NEXT( arg_node) = TRAVopt(FUNDEFS_NEXT(arg_node), arg_info);

  DBUG_RETURN( arg_node);

}


extern node *PRTvardecl (node * arg_node, info * arg_info)
{
  
  print_type(VARDECL_TYPE( arg_node));

  if (VARDECL_INIT( arg_node)) {
    printf("%s = ", VARDECL_NAME( arg_node));
    VARDECL_INIT( arg_node) = TRAVopt( VARDECL_INIT(arg_node), arg_info);

  } else {
    printf("%s;", VARDECL_NAME( arg_node));
  }

  VARDECL_DIMS( arg_node) = TRAVopt( VARDECL_DIMS(arg_node), arg_info);

  printf("\n");

  VARDECL_NEXT( arg_node) = TRAVopt( VARDECL_NEXT(arg_node), arg_info);

  
  
  return arg_node;
  
}


extern node *PRTifelse (node * arg_node, info * arg_info)
{

  DBUG_ENTER("PRTifelse");

  printf("if (");
  IFELSE_COND( arg_node) = TRAVdo( IFELSE_COND(arg_node), arg_info);
  printf("){\n\n");
  IFELSE_THEN( arg_node) = TRAVopt( IFELSE_THEN(arg_node), arg_info);
  printf("}\n\nelse {\n\n");
  IFELSE_ELSE( arg_node) = TRAVopt( IFELSE_ELSE(arg_node), arg_info);
  printf("}\n\n");
  DBUG_RETURN( arg_node);

}

extern node *PRTreturn (node * arg_node, info * arg_info)
{
  
  DBUG_ENTER("PRTreturn");
  printf("return ");
  RETURN_EXPR( arg_node) = TRAVopt(RETURN_EXPR( arg_node), arg_info);

  DBUG_RETURN( arg_node);

  
}




/** <!--******************************************************************-->
 *
 * @fn PRTstmts
 *
 * @brief Prints the node and its sons/attributes
 *
 * @param arg_node BinOp node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/

node *
PRTstmts (node * arg_node, info * arg_info)
{
  DBUG_ENTER ("PRTstmts");

  STMTS_STMT( arg_node) = TRAVdo( STMTS_STMT( arg_node), arg_info);
  
  STMTS_NEXT( arg_node) = TRAVopt( STMTS_NEXT( arg_node), arg_info);
  
  DBUG_RETURN (arg_node);
}


/** <!--******************************************************************-->
 *
 * @fn PRTassign
 *
 * @brief Prints the node and its sons/attributes
 *
 * @param arg_node BinOp node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/

node *
PRTassign (node * arg_node, info * arg_info)
{
  DBUG_ENTER ("PRTassign");

  if (ASSIGN_LET( arg_node) != NULL) {
    ASSIGN_LET( arg_node) = TRAVdo( ASSIGN_LET( arg_node), arg_info);
    printf( " = ");
  }
  
  ASSIGN_EXPR( arg_node) = TRAVdo( ASSIGN_EXPR( arg_node), arg_info);
  
  printf( ";\n");
  
  DBUG_RETURN (arg_node);
}


/** <!--******************************************************************-->
 *
 * @fn PRTbinop
 *
 * @brief Prints the node and its sons/attributes
 *
 * @param arg_node BinOp node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/

node *
PRTbinop (node * arg_node, info * arg_info)
{
  char *tmp;

  DBUG_ENTER ("PRTbinop");

  printf( "( ");

  BINOP_LEFT( arg_node) = TRAVdo( BINOP_LEFT( arg_node), arg_info);

  switch (BINOP_OP( arg_node)) {
    case BO_add:
      tmp = "+";
      break;
    case BO_sub:
      tmp = "-";
      break;
    case BO_mul:
      tmp = "*";
      break;
    case BO_div:
      tmp = "/";
      break;
    case BO_mod:
      tmp = "%";
      break;
    case BO_lt:
      tmp = "<";
      break;
    case BO_le:
      tmp = "<=";
      break;
    case BO_gt:
      tmp = ">";
      break;
    case BO_ge:
      tmp = ">=";
      break;
    case BO_eq:
      tmp = "==";
      break;
    case BO_ne:
      tmp = "!=";
      break;
    case BO_or:
      tmp = "||";
      break;
    case BO_and:
      tmp = "&&";
      break;
    case BO_unknown:
      DBUG_ASSERT( 0, "unknown binop detected!");
  }

  printf( " %s ", tmp);

  BINOP_RIGHT( arg_node) = TRAVdo( BINOP_RIGHT( arg_node), arg_info);

  printf( ")");

  DBUG_RETURN (arg_node);
}


/** <!--******************************************************************-->
 *
 * @fn PRTfloat
 *
 * @brief Prints the node and its sons/attributes
 *
 * @param arg_node Float node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/

node *
PRTfloat (node * arg_node, info * arg_info)
{
  DBUG_ENTER ("PRTfloat");

  printf( "%f", FLOAT_VALUE( arg_node));

  DBUG_RETURN (arg_node);
}



/** <!--******************************************************************-->
 *
 * @fn PRTnum
 *
 * @brief Prints the node and its sons/attributes
 *
 * @param arg_node Num node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/

node *
PRTnum (node * arg_node, info * arg_info)
{
  DBUG_ENTER ("PRTnum");

  printf( "%i", NUM_VALUE( arg_node));

  DBUG_RETURN (arg_node);
}


/** <!--******************************************************************-->
 *
 * @fn PRTboolean
 *
 * @brief Prints the node and its sons/attributes
 *
 * @param arg_node Boolean node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/

node *
PRTbool (node * arg_node, info * arg_info)
{
  DBUG_ENTER ("PRTbool");

  if (BOOL_VALUE( arg_node)) {
    printf( "true");
  }
  else {
    printf( "false");
  }
  
  DBUG_RETURN (arg_node);
}


/** <!--******************************************************************-->
 *
 * @fn PRTvar
 *
 * @brief Prints the node and its sons/attributes
 *
 * @param arg_node letrec node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/

node *
PRTvar (node * arg_node, info * arg_info)
{
  DBUG_ENTER ("PRTvar");

  printf( "%s", VAR_NAME( arg_node));

  DBUG_RETURN (arg_node);
}


/** <!--******************************************************************-->
 *
 * @fn PRTvarlet
 *
 * @brief Prints the node and its sons/attributes
 *
 * @param arg_node letrec node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/

node *
PRTvarlet (node * arg_node, info * arg_info)
{
  
  DBUG_ENTER ("PRTvarlet");

  printf( "%s", VARLET_NAME( arg_node));

  DBUG_RETURN (arg_node);
}


/** <!--******************************************************************-->
 *
 * @fn PRTsymboltableentry
 *
 * @brief Prints the node and its sons/attributes
 *
 * @param arg_node letrec node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/

node *PRTsymboltableentry (node * arg_node, info * arg_info)
{
  DBUG_ENTER ("PRTsymboltableentry");

  DBUG_RETURN (arg_node);
}

/** <!--******************************************************************-->
 *
 * @fn PRTerror
 *
 * @brief Prints the node and its sons/attributes
 *
 * @param arg_node letrec node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/

node *
PRTerror (node * arg_node, info * arg_info)
{
  bool first_error;

  DBUG_ENTER ("PRTerror");

  if (NODE_ERROR (arg_node) != NULL) {
    NODE_ERROR (arg_node) = TRAVdo (NODE_ERROR (arg_node), arg_info);
  }

  first_error = INFO_FIRSTERROR( arg_info);

  if( (global.outfile != NULL)
      && (ERROR_ANYPHASE( arg_node) == global.compiler_anyphase)) {

    if ( first_error) {
      printf ( "\n/******* BEGIN TREE CORRUPTION ********\n");
      INFO_FIRSTERROR( arg_info) = FALSE;
    }

    printf ( "%s\n", ERROR_MESSAGE( arg_node));

    if (ERROR_NEXT (arg_node) != NULL) {
      TRAVopt (ERROR_NEXT (arg_node), arg_info);
    }

    if ( first_error) {
      printf ( "********  END TREE CORRUPTION  *******/\n");
      INFO_FIRSTERROR( arg_info) = TRUE;
    }
  }

  DBUG_RETURN (arg_node);
}



/** <!-- ****************************************************************** -->
 * @brief Prints the given syntaxtree
 * 
 * @param syntaxtree a node structure
 * 
 * @return the unchanged nodestructure
 ******************************************************************************/

node 
*PRTdoPrint( node *syntaxtree)
{
  info *info;
  
  DBUG_ENTER("PRTdoPrint");

  DBUG_ASSERT( (syntaxtree!= NULL), "PRTdoPrint called with empty syntaxtree");

  printf( "\n\n------------------------------\n\n");

  info = MakeInfo();
  
  TRAVpush( TR_prt);

  syntaxtree = TRAVdo( syntaxtree, info);

  TRAVpop();

  info = FreeInfo(info);

  printf( "\n------------------------------\n\n");

  DBUG_RETURN( syntaxtree);
}

/**
 * @}
 */

// A helper function that prints the type of a variable.
void print_type(int type) {
  switch(type) {
    case 0 :
      printf("void ");
      break;
    case 1 :
      printf("bool ");
      break;
    case 2 :
      printf("int ");
      break;
    case 3 :
      printf("float ");
      break;
    case 4 :
      printf("unknown ");
      break;
  }
}