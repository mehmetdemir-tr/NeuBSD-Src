#pragma once
#define ENOERR  0
#define EDOM    1
#define EILSEQ  2
#define ERANGE  3
#define errno_t int
#define errno   *(__errno_pointer())
extern errno_t* __errno_pointer(void);