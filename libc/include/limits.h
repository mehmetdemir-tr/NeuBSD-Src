#pragma once
#ifndef COMPILING_NEULIBC
#include <stddef.h>
#else
#include "stddef.h"
#endif
#define __STDC_VERSION_LIMITS_H__ 202311L

#define BOOL_MAX         (1)
#define BOOL_WIDTH       (sizeof(_Bool)*8)
#define CHAR_BIT         (sizeof(char)*8)
#define CHAR_MAX         (((unsigned char)-1)/2)
#define CHAR_MIN         (~CHAR_MAX | -CHAR_MAX)
#define CHAR_WIDTH       (CHAR_BIT)
#define INT_MAX          (((unsigned int)-1)/2)
#define INT_MIN          (~INT_MAX | -INT_MAX)
#define INT_WIDTH        (sizeof(int)*8)
#define LLONG_MAX        (((unsigned long long)-1)/2)
#define LLONG_MIN        (~LLONG_MAX | -LLONG_MAX)
#define LLONG_WIDTH      (sizeof(long long)*8)
#define LONG_MAX         (((unsigned long)-1)/2)
#define LONG_MIN         (~LONG_MAX | -LONG_MAX)
#define LONG_WIDTH       (sizeof(long)*8)
#define MB_LEN_MAX       1
#define SCHAR_MAX        CHAR_MAX
#define SCHAR_MIN        CHAR_MIN
#define SCHAR_WIDTH      CHAR_WIDTH
#define SHRT_MAX         (((unsigned short)-1)/2)
#define SHRT_MIN         (~SHRT_MAX | -SHRT_MAX)
#define SHRT_WIDTH       (sizeof(short)*8)
#define UCHAR_MAX        ((unsigned char)-1)
#define UCHAR_WIDTH      (sizeof(unsigned char)*8)
#define UINT_MAX         ((unsigned int)-1)
#define UINT_WIDTH       (sizeof(unsigned int)*8)
#define ULLONG_MAX       ((unsigned long long)-1)
#define ULLONG_WIDTH     (sizeof(unsigned long long)*8)
#define ULONG_MAX        ((unsigned long)-1)
#define ULONG_WIDTH      (sizeof(unsigned long)*8)
#define USHRT_MAX        ((unsigned short)-1)
#define USHRT_WIDTH      (sizeof(unsigned short)*8)
#define BITINT_MAXWIDTH  ULLONG_WIDTH
