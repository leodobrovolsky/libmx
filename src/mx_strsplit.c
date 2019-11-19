#include "libmx.h"

char **mx_strsplit(const char *s, char c) {
    if (!s)
        return NULL;

    int i = 0;
    int k = 0;
    int begin = 0;
    int end = 0;
    int size = mx_count_words(s, c);
    char *tmp = mx_strtrim_char(s, c);

    if (size == 0)
    	return NULL;

    char **result = (char**) malloc(sizeof(char*) * size);


    while(tmp[i]) {
    	while (tmp[i] && tmp[i] == c)
    		i++;

        begin = i;
    
	    while (tmp[i] && tmp[i] != c) 
	    	i++;

	    end = i;
        
        result[k] = mx_strndup(&tmp[begin], end - begin);
        k++;
    }
    
    result[k] = NULL;  
    mx_strdel(&tmp);

    return result;
}



