#include "libmx.h"

void *mx_memrchr(const void *s, int c, size_t n) {
    char *temp = (char*) s;
    
    for (unsigned long i = 0 ; i < n; i++)
        if (temp[i] == c)
            return (void*) &temp[i];
            
    return NULL;   
}

