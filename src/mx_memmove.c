#include "libmx.h"

void *mx_memmove(void *dst, const void *src, size_t len) {
    char *s1 = (char*) dst;
    char *s2 = (char*) src;

    for (unsigned long i = 0; i < len; i++)
        s1[i] = s2[i];
    
    dst = (void*) s1;
    return dst;
}
