#include "libmx.h"

char *mx_strtrim(const char *str) {
	if (!str)
		return NULL;
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
