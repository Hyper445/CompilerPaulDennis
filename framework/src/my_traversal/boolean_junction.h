#ifndef _BOOLEAN_JUNCTION_H_
#define _BOOLEAN_JUNCTION_H_

#include "types.h"

// extern node *MTprogram (node *arg_node, info *arg_info);
extern node *BJbinop (node *arg_node, info *arg_info);
extern node *BJdoBooleanJunction( node *syntaxtree);

#endif
