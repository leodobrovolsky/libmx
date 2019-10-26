#include "libmx.h"

int mx_memcmp(const void *s1, const void *s2, size_t n) {
	void *x = (void*)s1;
	x = (void*) s2;
	n++;
    return 0;
}
