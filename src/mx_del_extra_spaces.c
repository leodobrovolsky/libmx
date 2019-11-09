#include "libmx.h"

char *mx_del_extra_spaces(const char *str) {
    if (!str)
    	return NULL;
    
    int i = 0;
    int k = 0;
    int len = 0;

    while(str[i]) {
        if (!mx_isspace(str[i]))
            len++;
        i++;
    }
    len += mx_count_words_space(str) - 1;
    
    if (len < 0)
        return mx_strdup("\0");

    char *result = mx_strnew(len);
    
    i = 0;
    while(str[i]) {
    	while (mx_isspace(str[i]) && str[i])
    		i++;
        
	    while (!mx_isspace(str[i]) && str[i]) {
	    	result[k] = str[i];
	    	i++;
            k++;
	    }

        if (k + 1 < len) {
    	    result[k] = ' ';
            k++;   
        } 
    }

    return result;	
}



