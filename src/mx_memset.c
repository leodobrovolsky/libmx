#include "libmx.h"

void *mx_memset(void *b, int c, size_t len) {
	char *temp = (char*) b;

    for (unsigned long i = 0; i < len; i++)
    	temp[i] = c;

    return (void*) temp;
}
