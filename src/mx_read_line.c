#include "libmx.h"

int mx_read_line(char **lineptr, size_t buf_size, char delim, const int fd) {
    static char *str = NULL;
    static int last_fd = -2;
    char *buf = mx_strnew(buf_size);
    char *temp = NULL;
    size_t read_val = 1;
    size_t i = 0;
    size_t k = 0;
    int index = 0;

    printf("str: %s\n", str);

    mx_strdel(lineptr);

    
    if (last_fd == (int) fd)  
        temp = mx_strdup(str);
    
    if (temp == NULL)
        temp = mx_strnew(0);
    
    while (read_val > 0) {
        read_val = read(fd, buf, buf_size);
        index = mx_get_char_index(temp, delim);

        if (index >= 0) {
            mx_strdel(&str);
            str = mx_strndup(&temp[index + 1], buf_size - index); 
            *lineptr = mx_strndup(temp, index);
            mx_strdel(&temp);
            mx_strdel(&buf); 
            return index;       
        }       

        if (read_val == 0) {
            mx_strdel(&buf);
            mx_strdel(&temp);
            mx_strdel(&str);
            return -1;
        }
        else if (read_val > 0) {
            k = mx_strlen(temp);
            i = 0;

            temp = mx_realloc(temp, k + buf_size);

            while(buf[i] && buf[i] != delim) {
                temp[k] = buf[i];
                k++;
                i++;
            }

            temp[k] = '\0';
          
            if (i < buf_size) {
                mx_strdel(&str);
                str = mx_strndup(&buf[i + 1], buf_size - i);
                mx_strdel(&buf);
                *lineptr = mx_strdup(temp);
                mx_strdel(&temp);
                last_fd = (int) fd;
                return mx_strlen(*lineptr);
            }
            mx_strdel(&buf);
            buf = mx_strnew(buf_size);
        }
    }

    return -2;
}

