#include "libmx.h"

void *mx_memcpy(void *restrict dst, const void *restrict src, size_t n) {
	n++;
	void *x = (void*)dst;
	x = (void*) src;
    return x;
}
