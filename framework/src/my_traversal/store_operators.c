// /*****************************************************************************
//  *
//  * Module: store_operators
//  *
//  * Prefix: SO
//  *
//  * Description:
//  *
//  * This module implements a demo traversal of the abstract syntax tree that 
//  * sums up all integer constants and prints the result at the end of the traversal.
//  *
//  *****************************************************************************/


// #include "store_operators.h"

// #include "types.h"
// #include "tree_basic.h"
// #include "traverse.h"
// #include "dbug.h"

// #include "memory.h"
// #include "ctinfo.h"


// /*
//  * INFO structure
//  */

// struct INFO {
//   int mulAmount;
//   int divAmount;
//   int addAmount;
//   int subAmount;
//   int modAmount;
// };


// /*
//  * INFO macros
//  */

// #define INFO_MUL(n)  ((n)->mulAmount)
// #define INFO_DIV(n)  ((n)->divAmount)
// #define INFO_ADD(n)  ((n)->addAmount)
// #define INFO_SUB(n)  ((n)->subAmount)
// #define INFO_MOD(n)  ((n)->modAmount)


// /*
//  * INFO functions
//  */

// static info *MakeInfo(void)
// {
//   info *result;

//   DBUG_ENTER( "MakeInfo");

//   result = (info *)MEMmalloc(sizeof(info));

//   result->mulAmount = 0;
//   result->divAmount = 0;
//   result->addAmount = 0;
//   result->subAmount = 0;
//   result->modAmount = 0;

//   DBUG_RETURN( result);
// }

// static info *FreeInfo( info *info)
// {
//   DBUG_ENTER ("FreeInfo");

//   info = MEMfree( info);

//   DBUG_RETURN( info);
// }


// /*
//  * Traversal functions
//  */

// node *SObinop (node *arg_node, info *arg_info)
// {
//   DBUG_ENTER("SObinop");

//   switch (BINOP_OP(arg_node)) {
// 	  case BO_mul: 
// 	  	arg_info->mulAmount++;
// 		break;

// 	  case BO_div:
// 	    arg_info->divAmount++;
// 		break;

// 	  case BO_add:
// 	    arg_info->addAmount++;
// 		break;

// 	  case BO_sub:
// 	    arg_info->subAmount++;
// 		break;

// 	  case BO_mod:
// 	    arg_info->modAmount++;
// 		break;

//   }

//   BINOP_LEFT(arg_node) = TRAVdo(BINOP_LEFT(arg_node), arg_info);
//   BINOP_RIGHT(arg_node) = TRAVdo(BINOP_RIGHT(arg_node), arg_info);

//   DBUG_RETURN( arg_node);
// }


// /*
//  * Traversal start function
//  */

// node *SOdoStoreOperators( node *syntaxtree)
// {
//   info *arg_info;

//   DBUG_ENTER("SOdoStoreOperators");

//   arg_info = MakeInfo();

//   TRAVpush( TR_so);
//   syntaxtree = TRAVdo( syntaxtree, arg_info);
//   TRAVpop();

//   MODULE_MULAMOUNT(syntaxtree) = INFO_MUL(arg_info);
//   MODULE_DIVAMOUNT(syntaxtree) = INFO_DIV(arg_info);
//   MODULE_SUBAMOUNT(syntaxtree) = INFO_SUB(arg_info);
//   MODULE_ADDAMOUNT(syntaxtree) = INFO_ADD(arg_info);
//   MODULE_MODAMOUNT(syntaxtree) = INFO_MOD(arg_info);

//   arg_info = FreeInfo( arg_info);

//   DBUG_RETURN( syntaxtree);
// }
