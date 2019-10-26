#include "libmx.h"

void *mx_memrchr(const void *s, int c, size_t n) {
    char *temp = (char*) s;
    
    for (unsigned long i = n - 1 ; i >= 0; i--)
        if (temp[i] == c)
            return (void*) &temp[i];
            
    return NULL;   
}
