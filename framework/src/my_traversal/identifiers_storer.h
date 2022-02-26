#ifndef _IDENTIFIERS_STORER_H_
#define _IDENTIFIERS_STORER_H_

#include "types.h"

extern node *ISvar (node *arg_node, info *arg_info);
extern node *ISvarlet (node *arg_node, info *arg_info);
extern node *ISdoIdentifiersStorer( node *syntaxtree);

#endif
