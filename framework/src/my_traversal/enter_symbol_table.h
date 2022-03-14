#ifndef _ENTER_SYMBOL_TABLE_H_
#define _ENTER_SYMBOL_TABLE_H_

#include "types.h"

extern node *ESTprogram (node *arg_node, info *arg_info);
extern node *ESTfundef (node *arg_node, info *arg_info);
extern node *ESTfundec (node *arg_node, info *arg_info);
extern node *ESTglobdecl (node *arg_node, info *arg_info);
extern node *ESTglobdef (node *arg_node, info *arg_info);
extern node *ESTvardecl (node *arg_node, info *arg_info);
extern node *ESTfundef (node *arg_node, info *arg_info);
extern node *ISdoIdentifiersStorer( node *syntaxtree);

#endif
