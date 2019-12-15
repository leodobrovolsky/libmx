#include "libmx.h"

bool mx_write_to_file(const char *file, const char *str) {
    int fd = open(file, O_WRONLY);
    int write_index = 0;
    int len_str = mx_strlen(str);

    if (fd != -1) {
        write_index = write(fd, str, len_str);
        close(fd);
        if (write_index != len_str)
            return false;
    }
    else
        return false;
    return true;
}
