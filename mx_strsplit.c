#include <stdlib.h>
#include <stdio.h>

char *mx_strndup(const char *s1, size_t n);
int mx_count_words(const char *str, char delimiter);


char **mx_strsplit(const char *s, char c) {
    if (!s)
        return NULL;

    int i = 0;
    int k = 0;
    int begin = 0;
    int end = 0;
    int size = mx_count_words(s, c);

    if (size == 0)
    	return NULL;

    char **result = (char**) malloc(sizeof(char*) * size);


    while(s[i]) {
    	while (s[i] && s[i] == c)
    		i++;

        begin = i;

	    while (s[i] && s[i] != c) 
	    	i++;

	    end = i;

        result[k] = mx_strndup(&s[begin], end - begin);
        k++;
    }

    return result;
}



