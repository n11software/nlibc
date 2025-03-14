/*
 * Copyright (c) 2021 Ariston Lorenzo. All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

#include <stdint.h>

#ifndef _STDDEF_H
#define _STDDEF_H

typedef int64_t 	 ssize_t;
typedef __SIZE_TYPE__    size_t;
typedef __PTRDIFF_TYPE__ ptrdiff_t;
typedef long             ssize_t;
typedef long             suseconds_t;

#ifdef __cplusplus
#define NULL 0
#else
#define NULL ((void*)0)
#endif

#define offsetof(type, member) __builtin_offsetof(type, member)

#endif /* _STDDEF_H */
