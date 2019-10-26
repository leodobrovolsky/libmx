#include "libmx.h"

void *mx_realloc(void *ptr, size_t size) {
	if (!ptr || malloc_size(ptr) == 0)
		return NULL;
    
    unsigned long len = malloc_size(ptr);
    void *src = malloc(size);

    src = mx_memcpy(src, ptr, len);

    free(ptr);

    return src;
}
