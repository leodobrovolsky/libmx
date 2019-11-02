#include "libmx.h"

void *mx_realloc(void *ptr, size_t size) {
	if (!ptr)
		return NULL;
    
    size_t len = mx_strlen(ptr);
    void  *str = NULL;
    
    if (len > size) {
        str = malloc(len);
        str = mx_memcpy(str, ptr, len);
        free(ptr);
        return str;
    }
    else {
        str = malloc(size);
        str = mx_memcpy(str, ptr, size);
        free(ptr);
        return str;
    }
    return str;
}
