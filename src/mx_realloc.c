#include "libmx.h"

void *mx_realloc(void *ptr, size_t size) {
	if (!ptr)
		return malloc(size);
    
    size_t len = malloc_size(ptr);
    void  *str = NULL;
    
    if (len >= size) {
        return ptr;
    }
    else {
        str = malloc(size);
        str = mx_memcpy(str, ptr, size);
        free(ptr);
        return str;
    }
    return str;
}
