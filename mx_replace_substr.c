#include <stdio.h>
#include <stdlib.h>
int mx_strlen(const char *s);
char *mx_strstr(const char *haystack, const char *needle);
void mx_swap_char(char *s1, char *s2);
char *mx_strjoin(char const *s1, char const *s2);
char *mx_strncpy(char *dst, const char *src, int len);

char *mx_replace_substr(const char *str, const char *sub, const char *replace) {
    char *sub_search = mx_strstr(str, sub);
    char *result = 	str;
    int index = mx_strlen(str) - mx_strlen(result);
    
    while (sub_search) {
	    result = mx_strjoin(result, replace);
	    result = mx_strjoin(result, sub_search);
    }

    return result;
}
