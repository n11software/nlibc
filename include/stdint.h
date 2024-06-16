#pragma once

#include "sys/cdefs.h"

__BEGIN_DECLS

typedef unsigned long int uint64_t;
typedef unsigned int uint32_t;
typedef unsigned short int uint16_t;
typedef unsigned char uint8_t;

typedef long int int64_t;
typedef int int32_t;
typedef short int int16_t;
typedef signed char int8_t;

typedef unsigned char uint_fast8_t;
typedef unsigned long int uint_fast16_t;
typedef unsigned long int uint_fast32_t;
typedef unsigned long int uint_fast64_t;

typedef signed char int_fast8_t;
typedef long int int_fast16_t;
typedef long int int_fast32_t;
typedef long int int_fast64_t;

typedef unsigned char uint_least8_t;
typedef unsigned short int uint_least16_t;
typedef unsigned int uint_least32_t;
typedef unsigned long int uint_least64_t;

typedef signed char int_least8_t;
typedef short int int_least16_t;
typedef int int_least32_t;
typedef long int int_least64_t;

typedef long int intptr_t;
typedef unsigned long int uintptr_t;

#define __int8_t_defined 1
#define __uint8_t_defined 1
#define __int16_t_defined 1
#define __uint16_t_defined 1
#define __int32_t_defined 1
#define __uint32_t_defined 1
#define __int64_t_defined 1
#define __uint64_t_defined 1

typedef unsigned long int uintptr_t;
typedef long int intptr_t;

typedef unsigned long int uintmax_t;
#define UINTMAX_MAX __UINTMAX_MAX__
#define UINTMAX_MIN __UINTMAX_MIN__

typedef long int intmax_t;
#define INTMAX_MAX __INTMAX_MAX__
#define INTMAX_MIN (-INTMAX_MAX - 1)

#define INT8_MIN (-128)
#define INT16_MIN (-32767 - 1)
#define INT32_MIN (-2147483647 - 1)
#define INT64_MIN (-9223372036854775807LL - 1LL)
#define INT8_MAX (127)
#define INT16_MAX (32767)
#define INT32_MAX (2147483647)
#define INT64_MAX (9223372036854775807LL)
#define UINT8_MAX (255)
#define UINT16_MAX (65535)
#define UINT32_MAX (4294967295U)
#define UINT64_MAX (18446744073709551615ULL)

#define INTPTR_MAX INT32_MAX
#define INTPTR_MIN INT32_MIN
#define UINTPTR_MAX UINT32_MAX

#define INT_FAST8_MIN INT8_MIN
#define INT_FAST16_MIN INT16_MIN
#define INT_FAST32_MIN INT32_MIN
#define INT_FAST64_MIN INT64_MIN

#define INT_FAST8_MAX INT8_MAX
#define INT_FAST16_MAX INT16_MAX
#define INT_FAST32_MAX INT32_MAX
#define INT_FAST64_MAX INT64_MAX

#define UINT_FAST8_MAX UINT8_MAX
#define UINT_FAST16_MAX UINT16_MAX
#define UINT_FAST32_MAX UINT32_MAX
#define UINT_FAST64_MAX UINT64_MAX

#define INT_LEAST8_MIN INT8_MIN
#define INT_LEAST16_MIN INT16_MIN
#define INT_LEAST32_MIN INT32_MIN
#define INT_LEAST64_MIN INT64_MIN

#define INT_LEAST8_MAX INT8_MAX
#define INT_LEAST16_MAX INT16_MAX
#define INT_LEAST32_MAX INT32_MAX
#define INT_LEAST64_MAX INT64_MAX

#define UINT_LEAST8_MAX UINT8_MAX
#define UINT_LEAST16_MAX UINT16_MAX
#define UINT_LEAST32_MAX UINT32_MAX
#define UINT_LEAST64_MAX UINT64_MAX

#define INT8_C(x) x
#define UINT8_C(x) x

#define INT16_C(x) x
#define UINT16_C(x) x

#define INT32_C(x) x
#define UINT32_C(x) x

#define INT64_C(x) x##LL
#define UINT64_C(x) x##ULL

#define SIZE_MAX ((size_t)-1)

__END_DECLS
