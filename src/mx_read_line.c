#include "libmx.h"

int mx_read_line(char **lineptr, int buf_size, char delim, const int fd) {
    char buf;
    int i = 0;
    

    while(read(fd, &buf, 1)) {
    	if (!buf)
    		return -1;
       
    	if (buf == delim) 
            return i;

    	*lineptr[i] = buf;
        i++;
        
    	if (i  == buf_size - 1) 
            return i;
    }

    return 0;
}

