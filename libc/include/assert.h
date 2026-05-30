#pragma once
#define __STDC_VERSION_ASSERT_H__ 201112L
extern void __assert(int);
#ifdef NDEBUG
#    define assert(condition) ((void)0)
#else
#    define assert(condition) __assert(condition)
#endif