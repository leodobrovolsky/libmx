#include "libmx.h"

int mx_read_line(char **lineptr, int buf_size, char delim, const int fd) {
    static char *str = NULL;
    static int last_fd = 0;

    char *buf = mx_strnew(buf_size);
    int read_val = 1;
    int i = 0;
    int k = 0;


    mx_strdel(lineptr);

    if (last_fd == fd) {
        *lineptr = mx_strdup(str);
        mx_strdel(&str);
        str = mx_strnew(buf_size);
    }
    
    if (*lineptr == NULL)
        *lineptr = mx_strnew(0);
    
    while (read_val > 0) {
        read_val = read(fd, buf, buf_size);
        write(1, "\n+\n", 3);
        if (read_val == 0)
            return -1;

        else if (read_val > 0) {
            k = mx_strlen(*lineptr);
            i = 0;
            *lineptr = mx_realloc(*lineptr, k + buf_size);

            while(buf[i] && buf[i] != delim) {
                *lineptr[k] = buf[i];
                k++;
                i++;
            }
            *lineptr[k] = '\0';
            
            if (i < buf_size) {
                for (k = 0; i < buf_size; i++, k++)
                    buf[i] = str[k];

                mx_strdel(&buf);
                return mx_strlen(*lineptr);
            }
            mx_strdel(&buf);
        }
    }

    return -2;
}

