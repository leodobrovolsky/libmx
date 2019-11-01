#include "libmx.h"

char *mx_file_to_str(const char *file) {
    int fd = open(file, O_RDONLY);
    char *buf = NULL;
    char *str = NULL;

    if (fd != -1) {
        while(read(fd, buf, 1)) {
            if (!buf)
                return NULL;
            mx_strjoin(str, buf);
        }
        
    }
    else
        return NULL;

    return str;
}
