#include "libmx.h"

void *mx_memccpy(void *restrict dst, const void *restrict src, int c, size_t n) {
	char *s1 = (char*) dst;
	char *s2 = (char*) src;

    for (unsigned long i = 0; i < n; i++) {
    	if (s2[i] == c)
    		return NULL;
    	s1[i] = s2[i];
    }

    dst = (void*) s1;

    return dst;
}
