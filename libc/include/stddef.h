#pragma once
#define __STDC_VERSION_STDDEF_H__ 202311L

typedef long long           ptrdiff_t;
typedef void*               nullptr_t;
typedef long long           max_align_t;
typedef char                wchar_t;
typedef unsigned long long  size_t;
typedef long long           ssize_t;

#ifndef NULL
#define NULL ((void*)0)
#endif
#define unreachable() __builtin_unreachable()
#define offsetof(P, D) ((size_t) &((P*)0)->D)