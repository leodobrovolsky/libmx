#include "libmx.h"

void *mx_memccpy(void *restrict dst, const void *restrict src, int c, size_t n) {
	c = n;
	void *x = (void*) src;
	x = (void*) dst;
    return x;
}
