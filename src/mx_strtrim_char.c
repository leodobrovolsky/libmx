#include "libmx.h"

char *mx_strtrim_char(const char *str, char c) {
    int begin = 0;
    int end = mx_strlen(str) - 1;

    while(str[begin] && str[begin] == c) 
        begin++;
    
    while (str[end] && str[end] == c)
        end--;
    
    if (end < begin)
        return mx_strnew(0);
         
    return mx_strncpy(mx_strnew(end - begin + 1), &str[begin], end - begin + 1);
}
