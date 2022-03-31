#ifndef _MAKE_CONSTANT_TABLE_H_
#define _MAKE_CONSTANT_TABLE_H_

#include "types.h"

extern node *MCTprogram (node *arg_node, info *arg_info);
extern node *MCTbinop (node *arg_node, info *arg_info);
extern node *MCTvardecl (node *arg_node, info *arg_info);
extern node *MCTfloat (node *arg_node, info *arg_info);
extern node *MCTnum (node *arg_node, info *arg_info);
extern node *MCTdoMakeConstantTable( node *syntaxtree);

#endif
