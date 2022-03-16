
/**
 * @file traverse_tables.h
 *
 * This file defines the function tables for traversal.
 *
 * THIS FILE HAS BEEN GENERATED USING
 * $Id: traverse_tables.h.xsl 14593 2006-01-31 17:09:55Z cg $.
 * DO NOT EDIT THIS FILE AS MIGHT BE CHANGED IN A LATER VERSION.
 *
 * ALL CHANGES MADE TO THIS FILE WILL BE OVERWRITTEN!
 *
 */

#ifndef _SAC_TRAVERSE_TABLES_H_
#define _SAC_TRAVERSE_TABLES_H_

#include "types.h"

typedef travfun_p travfunarray_t[33];

typedef travfunarray_t travtables_t[6];

typedef travfun_p preposttable_t[6];

extern travtables_t travtables;
extern preposttable_t pretable;
extern preposttable_t posttable;
extern const char *travnames[6];

#endif				/* _SAC_TRAVERSE_TABLES_H_ */
