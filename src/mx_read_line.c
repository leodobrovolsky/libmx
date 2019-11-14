#include "libmx.h"

int mx_read_line(char **lineptr, int buf_size, char delim, const int fd) {
    static char *str = NULL;
    static int last_fd = 0;
    char *buf = mx_strnew(buf_size);
    int read_val = 1;
    int delim_index = 0;
    mx_strdel(lineptr);

    if (last_fd == fd) {
        *lineptr = mx_strdup(str);
        str = mx_strnew(buf_size);
    }

    
    while (read_val > 0) {
        read_val = read(fd, buf, buf_size);

        if (read_val == 0)
            return -1;
        else {
            delim_index = mx_get_char_index(buf, delim);
            if (delim_index == -1) {
                *lineptr = mx_strjoin(*lineptr, buf);
                buf = mx_strnew(buf_size);
            }
            else {
                if (*lineptr)
                    *lineptr = mx_strndup(*lineptr, mx_strlen(*lineptr) - read_val + delim_index);
                else
                    *lineptr = mx_strndup(buf, delim_index);
     
                str = mx_strdup(&buf[delim_index + 1]);
                mx_strdel(&buf);
                last_fd = fd;
                return mx_strlen(*lineptr);
            }
        }
    }

    return -2;
}

