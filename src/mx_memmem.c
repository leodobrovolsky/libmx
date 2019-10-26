#include "libmx.h"

void *mx_memmem(const void *big, size_t big_len, const void *little, size_t little_len) {
	little_len++;
	void *x = (void*) big;
	big_len++;
	x = (void*)little;
	return (void*) little;
}
