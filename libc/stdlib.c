#include "../libbridge/bridge.h"
#include "include/stdlib.h"
#include "include/string.h"
#include "include/ctype.h"
#include "include/limits.h"
#include "include/stdbool.h"
#include "include/errno.h"
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

int __strtab(const char* str) {
    if (str == NULL) return 10;
    if (*str == '-' || *str == '+') str++;
    if (*str == '\0') return 10;
    if (*str == '0' && tolower((unsigned char)str[1]) == 'x') return 16;
    if (*str == '0' && tolower((unsigned char)str[1]) == 'b') return 2; else if (*str == '0') return 8;
    return 10;
}
bool __strbch(char ch, int base) {
    ch = tolower((unsigned char)ch);
    if (base <= 10) {
        return '0' <= ch && ch < ('0' + base) && isdigit((unsigned char)ch);
    } else {
        return (isdigit((unsigned char)ch) || ('a' <= ch && ch < ('a' + base - 10))) && isalnum((unsigned char)ch);
    }
}
int __strdgt(char ch, int base) {
    ch = tolower((unsigned char)ch);
    if (!(isalnum((unsigned char)ch))) return 0;
    if (base <= 10 || ch <= '9') {
        return ch - '0';
    } else {
        return ch - 'a' + 10;
    }
}
unsigned long long strtoull(const char* str, char** endptr, int base) {
    if (str == NULL) return 0;
    while (isspace(*str)) str++;
    bool neg = false;
    if (*str == '-' || *str == '+') { neg = *str == '-' ? true : false; str++; }
    int pred = __strtab(str);
    if (base == 0) {
        switch (pred) {
            case 2: str += 2; break;
            case 8: str += 1; break;
            case 16: str += 2; break;
        }
        base = pred;
    }
    unsigned long long num = 0;
    while (*str) {
        if (__strbch(*str, base)) {
            num = num * base + __strdgt(*str, base);
            str++;
        } else break;
    }
    if (endptr != NULL) *endptr = str;
    return neg ? -num : num;
}
unsigned long strtoul(const char* str, char** endptr, int base) {
    unsigned long long result = strtoull(str, endptr, base);
    if (result > ULONG_MAX) {
        errno = ERANGE;
        return ULONG_MAX;
    }
    return (unsigned long)result;
}
long strtol(const char* str, char** endptr, int base) {
    unsigned long long result = strtoull(str, endptr, base);
    if ((long)result > LONG_MAX) {
        errno = ERANGE;
        return LONG_MAX;
    }
    if ((long)result < LONG_MIN) {
        errno = ERANGE;
        return LONG_MIN;
    }
    return (long)result;
}
long long strtoll(const char* str, char** endptr, int base) {
    unsigned long long result = strtoull(str, endptr, base);
    if ((long long)result > LLONG_MAX) {
        errno = ERANGE;
        return LLONG_MAX;
    }
    if ((long long)result < LLONG_MIN) {
        errno = ERANGE;
        return LLONG_MIN;
    }
    return (long long)result;
}

long double strtold(const char* str, char** endptr) {
    if (str == NULL) return 0;
    while (isspace(*str)) str++;
    bool neg = false;
    if (*str == '-' || *str == '+') { neg = *str == '-' ? true : false; str++; }
    int pred = __strtab(str);
    pred = pred == 16 ? 16 : 10;
    char* np;
    if (pred == 16) str+=2;
    long long A = strtoll(str, &np, pred);
    long long B = 0;
    long double frac = 0;
    if (*np == '.') {
        np++;
        long double place = 1.0L / pred;
        while (__strbch(*np, pred)) {
            frac += __strdgt(*np, pred) * place;
            place /= pred;
            np++;
        }
    }
    if (((*np == 'p' || *np == 'P') && pred == 16) || ((*np == 'e' || *np == 'E')) && pred == 10) {
        char* op = np + 1;
        B = strtoll(op, &np, 10);
    }
    long double base = (pred == 16) ? 2.0L : 10.0L;
    long double result = frac + (long double)A;
    for (long long i = 0; i < B; i++) {
        result *= base;
        if (result > 1e100L) { result = __builtin_huge_vall(); break; }
    }
    for (long long i = 0; i > B; i--) {
        result /= base;
        if (result < 1e-100L) { result = 0.0L; break; }
    }
    if (endptr) *endptr = np;
    return neg ? -result : result;
}

double strtod(const char* str, char** endptr) {
    return (double)strtold(str, endptr);
}

float strtof(const char* str, char** endptr) {
    return (float)strtod(str, endptr);
}