#include <unistd.h>
#include <fcntl.h>
#include <string.h>
char *mx_file_to_str(const char *file) {
    int fd = open(file, O_RDONLY);
    char *buf = NULL;
    char *str = NULL;

    if (fd != -1) {
        while(read(fd, buf, 1)) {
            if (!buf)
                return NULL;
            strjoin(str, buf);
        }
        
    }
    else
        return NULL;

    return str;
}
