#ifndef _PRINT_TABLE_H_
#define _PRINT_TABLE_H_

#include "types.h"

extern node *PTsymboltable (node *arg_node, info *arg_info);
extern node *PTsymboltableentry (node *arg_node, info *arg_info);

extern node *PTdoPrintTable( node *syntaxtree);

#endif
