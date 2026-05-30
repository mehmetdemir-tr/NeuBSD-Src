#pragma once
#define NULL        ((void*)0)
#define MB_CUR_MAX  1

typedef struct {
    int quot;
    int rem;
} div_t;

typedef struct {
    long quot;
    long rem;
} ldiv_t;

typedef struct {
    long long quot;
    long long rem;
} lldiv_t;

// ++ libbridge defs ++

void abort(void);
char* getenv(const char* name);
int system(const char* command);
void _Exit(int status);

int rand(void);
void srand(unsigned int seed);

void* realloc(void* ptr, size_t size);

// -- libbridge defs --

int atexit(void (*func)(void));
int at_quick_exit(void (*func)(void));
void exit(int status)
_Noreturn void quick_exit(int status);

void* calloc(size_t num, size_t size);
void free(void* ptr);
void* malloc(size_t size);

int abs(int n);
div_t div(int number, int denom);
long labs(long n);
ldiv_t ldiv(long number, long denom);
long long llabs(long long n);
lldiv_t lldiv(long long number, long long denom);

int mblen(const char* pmb, size_t max);
int mbtowc(wchar_t* pwc, const char* pmb, size_t max);
int wctomb(char* pmb, wchar_t wc);
size_t mbstowcs(wchar_t* dest, const char* src, size_t max);
size_t wcstombs(char* dest, const wchar_t* src, size_t max);

