#ifndef _CONSTANT_FOLDING_H_
#define _CONSTANT_FOLDING_H_

#include "types.h"

extern node* CFbinop(node* arg_node, info* arg_info);
extern node *CFdoConstantFolding( node *syntaxtree);

#endif
