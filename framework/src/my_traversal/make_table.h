#ifndef _MAKE_TABLE_H_
#define _MAKE_TABLE_H_

#include "types.h"

// extern node *MTprogram (node *arg_node, info *arg_info);
extern node *MTfundef (node *arg_node, info *arg_info);
extern node *MTglobdecl (node *arg_node, info *arg_info);
extern node *MTglobdef (node *arg_node, info *arg_info);
extern node *MTvardecl (node *arg_node, info *arg_info);
extern node *MTvar (node *arg_node, info *arg_info);

extern node *MTdoMakeTable( node *syntaxtree);

#endif
