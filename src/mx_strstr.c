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


char *mx_strstr(const char *haystack, const char *needle) {
    int len_s1 = mx_strlen(haystack);
    int len_s2 = mx_strlen(needle);
    if (!len_s2)
        return (char*) haystack;

    for (int i = 0; i <= len_s1 - len_s2; i++) 
        if (!mx_strncmp(&haystack[i], needle, len_s2))
            return (char*) &haystack[i];

    return NULL;
}
