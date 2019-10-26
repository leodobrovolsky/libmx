#include "libmx.h"

static bool mx_isspace(char c) {
    if (c == 32 || (c >= 9 && c <= 13))
        return true;
    else  
        return false;
}

static int mx_count_words_space(const char *str) {
    int i = 0;
    int indifier = 0;
    int words = 0;
    
    while(mx_isspace(str[i]))
        i++;

    if (str[i])
        words++;

    while(str[i]) {
        if (mx_isspace(str[i]))
            indifier++;
        else 
            if (indifier > 0) {
                indifier = 0;
                words++;
            }
        i++;
    }
    return words;
}


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



