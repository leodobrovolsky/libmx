#include "libmx.h"

char *mx_file_to_str(const char *file) {
    int len = 0;
    int fd = open(file, O_RDONLY);
    char buf;

    if (fd != -1) {
        while(read(fd, &buf, 1)) {
            if (!buf)
                return NULL;
            len++;
        }
        
    }
    else
        return NULL;

    close(fd);
    
    char *str = mx_strnew(len);
    int fd2 = open(file, O_RDONLY);
    
    if (fd2 != -1)
        read(fd2, str, len);
    else
        return NULL;

    close(fd2);

    return str;
}
