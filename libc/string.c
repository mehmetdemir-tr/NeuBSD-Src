#include "include/string.h"
#include "include/stdlib.h"
#include "include/errno.h"
char* strcpy(char* restrict dest, const char* restrict src) {
    char* ret = dest;
    while ((*dest++ = *src++));
    return ret;
}

char *strncpy(char *restrict dest, const char *restrict src, size_t count) {
    if (count == 0) return dest;
    char* ret = dest;
    while (count && (*dest++ = *src++)) count--;
    while (count--)
        *dest++ = 0;
    return ret;
}

char* strcat(char* dest, const char* src) {
    char *ret = dest;
    while(*dest)
        dest++;
    while((*dest++ = *src++));
    return ret;
}

char* strncat(char* dest, const char* src, size_t n) {
    char *ptr = dest + strlen(dest);
    while(n-- && *src) {
        *ptr++ = *src++;
    }
    *ptr = '\0';
    return dest;
}

size_t strxfrm(char *dest, const char *src, size_t n) {
    size_t len = strlen(src);
    if (dest && n > 0)
        strncpy(dest, src, n);
    return len;
}

char* strdup(const char* src) {
    if (!src) return NULL;
    size_t sl = strlen(src);
    char* neu = (char*)malloc(sl + 1);
    if (!neu) return NULL;
    memset(neu, '\0', sl + 1);
    return strcpy(neu, src);
}

char* strndup(const char *src, size_t size) {
    if (!src) return NULL;
    size_t ln = strnlen(src, size);
    char* buf = (char*)malloc(ln + 1);
    if (!buf) return NULL;
    memset(buf, '\0', ln + 1);
    memcpy(buf, src, ln);
    buf[ln] = '\0';
    return buf;
}

size_t strlen(const char* str) {
    if (!str) return 0;
    size_t q = 0;
    while (*str++) q++;
    return q;
}

size_t strnlen(const char* str, size_t n) {
    if (!str) return 0;
    size_t q = 0;
    while (*str++ && q < n) q++;
    return q;
}

char* strerror(int errnum) {
    switch (errnum) {
        case ENOERR:
            return "No error";
        case EILSEQ:
            return "Illegal sequence";
        case EDOM:
            return "Domain error";
        case ERANGE:
            return "Range error";
    }
    return "Unknown error";
}

int strcmp(const char *str1, const char *str2) {
    if (str1 == NULL && str2 == NULL) return 0;
    if (str1 == NULL) return -1;
    if (str2 == NULL) return 1;
    while(*str1 && (*str1==*str2)) {
       str1++;
       str2++;
    }
    return (unsigned char)*str1 - (unsigned char)*str2;
}

int memcmp(const void *ptr1, const void *ptr2, size_t n) {
    if (ptr1 == NULL && ptr2 == NULL) return 0;
    if (ptr1 == NULL) return -1;
    if (ptr2 == NULL) return 1;
    const unsigned char *p1 = ptr1, *p2 = ptr2;
    while(n--) {
        if(*p1 != *p2)
            return *p1 - *p2;
        else {
            p1++;
            p2++;  	
        }   
    }
    return 0;
}

int strncmp(const char *str1, const char *str2, size_t n) {
    if (str1 == NULL && str2 == NULL) return 0;
    if (str1 == NULL) return -1;
    if (str2 == NULL) return 1;
    while(n--) {
        unsigned char a = (unsigned char)*str1++;
        unsigned char b = (unsigned char)*str2++;
        if(a != b)
    	    return a - b;
        if (a == '\0')
            return 0;
    }
    return 0;
}

int strcoll(const char* s1, const char* s2) {
    return strcmp(s1, s2);
}

char* strchr(const char *str, int c) {
    if (str == NULL) return NULL;
    do {
        if(*str == (char)c) {
            return (char*)str;
        }
    } while (*str++);
    
    return NULL;
}


char* strrchr(const char *str, int c) {
    if (str == NULL) return NULL;
    char* ret = 0;
    do {
        if(*str == (char)c)
            ret=str;
    } while(*str++);
    return ret;
}

size_t strspn(const char *str1, const char *str2) {
    if (str1 == NULL || str2 == NULL) return 0;
    size_t ret = 0;
    while(*str1 && strchr(str2,*str1++))
        ret++;
    return ret;
}


size_t strcspn(const char *str1, const char *str2) {
    if (str1 == NULL || str2 == NULL) return 0;
    size_t ret=0;   
    while(*str1) {    
        if(strchr(str2, *str1))
            return ret;
        else {
            str1++;
            ret++;
        }   
    }		    		
    return ret;
}

char* strpbrk(const char *str1, const char *str2) {
    if (str1 == NULL || str2 == NULL) return NULL;
    while(*str1) {
        if(strchr(str2, *str1++))
            return (char*)--str1;
    }  
  
    return NULL;
}


char* strstr(const char *str1, const char *str2) {
    if (str1 == NULL || str2 == NULL) return NULL;
    size_t n = strlen(str2);
    if (*str2 == '\0') return (char*)str1;
    while(*str1) {
        if(!memcmp(str1++, str2, n))
            return str1-1;
    }		

    return NULL;
}

char* strtok(char *str, const char *delim) {
    if (delim == NULL) return str;
    static char* p=0;

    if(str)
        p=str;
    else if(!p)
        return NULL;
    str = p+strspn(p,delim);
    p = str+strcspn(str,delim);
    if(p==str)
        return p=NULL;

    p = *p ? p+1 : 0;

    return str;
}

void *memchr(const void *ptr, int c, size_t n) {
    if (ptr == NULL) return NULL;
    unsigned char *p = (unsigned char*)ptr;
    while(n--) {
        if(*p != (unsigned char)c)
            p++;
        else
            return p;
    }	
  
    return NULL;
}

void* memset(void *dest, int c, size_t n) {
    if (dest == NULL) return dest;
    unsigned char *ptr = dest;
    while(n--)
        *ptr++ = (unsigned char)c;
    return dest;
}

void *memcpy(void *dest, const void *src, size_t n) {
    if (dest == NULL || src == NULL) return dest;
    unsigned char *d = dest;
    const unsigned char *s = src;
    while(n--)
        *d++ = *s++;
    return dest;
}

void *memmove(void *dest, const void *src, size_t n) {
    if (n == 0) return dest;
    unsigned char *d = dest;
    const unsigned char *s = src;
    if(d < s) {
        while(n--)
            *d++ = *s++;
    }
    else {
        unsigned char *lasts = s + (n-1);
        unsigned char *lastd = d + (n-1);
        while(n--)
            *lastd-- = *lasts--;
    }
    return dest;
}

void* memccpy(void* restrict s1, const void* restrict s2, int c, size_t n) {
    if (s1 == NULL || s2 == NULL) return NULL;
    unsigned char *d = (unsigned char*)s1;
    const unsigned char *s = (const unsigned char*)s2;
    unsigned char ch = (unsigned char)c;
    while(n--)
        if ((*d++ = *s++) == ch) {
            return d;
        }
    return NULL;
}