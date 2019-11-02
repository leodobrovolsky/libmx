#include "libmx.h"

int mx_read_line(char **lineptr, int buf_size, char delim, const int fd) {
    char *buf = malloc(buf_size);
    int read_val = 0;
    
    while(!read_val) {
        read_val = read(fd, buf, buf_size);
        
        if (read_val > 0) {
            *lineptr = mx_strjoin(*lineptr, buf);
            if (mx_get_char_index(*lineptr, delim) == -1)
                continue;
            else {
                *lineptr = mx_strndup(*lineptr, mx_get_char_index(*lineptr, delim));
                return mx_strlen(*lineptr);
            }
        }
        else if (read_val == 0)
            return 0;
        else
            return -1;
    }
    return -1;
}

