#ifndef _MAKE_EXPORT_TABLE_H_
#define _MAKE_EXPORT_TABLE_H_

#include "types.h"

extern node *METprogram (node *arg_node, info *arg_info);
extern node *METfundef (node *arg_node, info *arg_info);
extern node *METdoMakeExportTable( node *syntaxtree);

#endif
