#include "libmx.h"

static bool mx_isspace(char c) {
    if (c == 32 || (c >= 9 && c <= 13))
        return true;
    else  
        return false;
}

char *mx_strtrim(const char *str) {
    int begin = 0;
    int end = mx_strlen(str) - 1;

    while(str[begin] && mx_isspace(str[begin])) 
        begin++;
    
    while (str[end] && mx_isspace(str[end]))
        end--;
    
    if (end < begin)
        return mx_strnew(0);
         
    return mx_strncpy(mx_strnew(end - begin + 1), &str[begin], end - begin + 1);
}
