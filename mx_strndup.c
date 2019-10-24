#include <stdlib.h>

int mx_strlen(const char *s);

char *mx_strnew(const int size);

char *mx_strncpy(char *dst, const char *src, int len);

char *mx_strndup(const char *s1, size_t n) {
    return mx_strncpy(mx_strnew(n), s1, n);
}
