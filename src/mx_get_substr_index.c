#include "libmx.h"

static int mx_strncmp(const char *s1, const char *s2, int n) {
    int i = 0;
    while (s1[i] && i < n) {
        if (s1[i] != s2[i]) 
            return s1[i] - s2[i];
        i++;
    }
    if (s2[i] && i < n) {
        return s1[i] - s2[i];
    }
    return 0;
}

int mx_get_substr_index(const char *str, const char *sub) {
    if (!str || !sub)
        return -2;
    int len_str = mx_strlen(str);
    int len_sub = mx_strlen(sub);

    for (int i = 0; i <= len_str - len_sub; i++) 
        if (!mx_strncmp(&str[i], sub, len_sub))
            return i;

    return -1;
}
