#include "libmx.h"

int mx_read_line(char **lineptr, int buf_size, char delim, const int fd) {
    static char *str = NULL;
    char *buf = malloc(buf_size);
    int read_val = -1;
    int index = 0;
    
    while(read_val) {
        read_val = read(fd, buf, buf_size);
        
        if (read_val > 0) {
            str = mx_strjoin(str, buf);
            if (mx_get_char_index(buf, delim) == -1)
                continue;
            else {
                for (index = mx_strlen(str) - 1; index >= 0; index--)
                    if (str[index] == delim)
                        break;
                *lineptr = mx_strndup(str, index);
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

