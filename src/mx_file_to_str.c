#include "libmx.h"

char *mx_file_to_str(const char *file) {
    int fd = open(file, O_RDONLY);
    char *buf = mx_strnew(0);
    char *str = NULL;
    

    if (fd != -1) {
        while(read(fd, buf, 1) > 0) {
            if(!buf)
                return NULL;
            str = mx_strjoin(str, buf);
        }
    }
    else
        return NULL;
    
    close (fd);

    mx_strdel(&buf);

    return str;
}
