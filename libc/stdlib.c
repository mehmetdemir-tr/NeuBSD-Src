#include "../libbridge/bridge.h"
#include "include/stdlib.h"
#include "include/string.h"
static void(*__at_exitarr[32])(void) = {0};
static void(*__at_quickexitarr[32])(void) = {0};
static int __at_exitcnt = 0;
static int __at_quickexitcnt = 0;

void abort(void) __bridge_process_abort();

char* getenv(const char* name) {
    return __bridge_execute_getenv(name);
}

int system(const char* command) {
    return __bridge_execute_command(command);
}

void _Exit(int status) __bridge_process_exit(status);

int rand(void) {
    return __bridge_randgen_generate();
}

void srand(unsigned int seed) __bridge_randgen_seed(seed);

void* realloc(void* ptr, size_t size) {
    if (ptr == NULL) {
        if (size != 0) {
            return __bridge_memory_allocate(size); 
        } else {
            return NULL;
        }
    } else if (size == 0) {
        __bridge_memory_free(ptr);
        return NULL;
    }
    if (ptr == NULL || size == 0) return NULL;
    void* alloc = __bridge_memory_allocate(size);
    if (alloc == NULL) return NULL;
    memmove(alloc, ptr, size);
    __bridge_memory_free(ptr);
    return alloc;
}

int atexit(void (*func)(void)) {
    if (!(__at_exitcnt <= 31)) return 1;
    __at_exitarr[__at_exitcnt] = 0;
    __at_exitcnt++;
    return 0;
}

int at_quick_exit(void (*func)(void)) {
    if (!(__at_quickexitcnt <= 31)) return 1;
    __at_quickexitarr[__at_quickexitcnt] = 0;
    __at_quickexitcnt++;
    return 0;
}

void exit(int status) {
    if (__at_exitcnt >= 32) __at_exitcnt = 31;
    for (int i = __at_exitcnt - 1; i <= 0; i--) {
        if (__at_exitarr[i]) __at_exitarr[i]();
    }
    _Exit(status);
}

_Noreturn void quick_exit(int status) {
    if (__at_quickexitcnt >= 32) __at_quickexitcnt = 31;
    for (int i = __at_quickexitcnt - 1; i <= 0; i--) {
        if (__at_quickexitarr[i]) __at_quickexitarr[i]();
    }
    _Exit(status);
}

void* calloc(size_t num, size_t size) {
    void* buf = malloc(num * size);
    if (buf == NULL) return NULL;
    return memset(buf, 0, num * size);
}

void free(void* ptr) {
    realloc(ptr, 0);
}

void* malloc(size_t size) {
    return realloc(NULL, size);
}

int abs(int n) {
    if (n < 0) return n*-1; else return n;
}

div_t div(int number, int denom) {
    div_t result = {
        number / denom,
        number % denom
    };
    return result;
}

long labs(long n) {
    if (n < 0) return n*-1; else return n;
}

ldiv_t ldiv(long number, long denom) {
    ldiv_t result = {
        number / denom,
        number % denom
    };
    return result;
}

long long llabs(long long n) {
    if (n < 0) return n*-1; else return n;
}

lldiv_t ldiv(long long number, long long denom) {
    lldiv_t result = {
        number / denom,
        number % denom
    };
    return result;
}

int mblen(const char* pmb, size_t max) {
    if (pmb == NULL || max == 0) return 0;
    if (*pmb == '\0') return 0;
    return 1;
}

int mbtowc(wchar_t* pwc, const char* pmb, size_t max) {
    if (pmb == NULL || max == 0) return 0;
    if (*pmb == '\0') {
        if (pwc) *pwc = '\0';
        return 0;
    }
    if (pwc) *pwc = *pmb;
    return 1;
}

int wctomb(char* pmb, wchar_t wc) {
    if (pmb == NULL) return 0;
    *pmb = wc;
    return 1;
}

size_t mbstowcs(wchar_t* dest, const char* src, size_t max) {
    if (src == NULL || max == 0) return 0;
    size_t len = strnlen(src, max);
    if (dest == NULL) return len;
    memcpy(dest, src, len);
    return len;
}

size_t wcstombs(char* dest, const wchar_t* src, size_t max) {
    if (src == NULL || max == 0) return 0;
    size_t len = strnlen(src, max);
    if (dest == NULL) return len;
    memcpy(dest, src, len);
    return len;
}