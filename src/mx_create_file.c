#include "libmx.h"

bool mx_create_file(char *file) {
    int fd = open(file, O_CREAT, (S_IRUSR | S_IWUSR));

    close(fd);
    if (fd < 3) 
        return false;
    return true;
}
