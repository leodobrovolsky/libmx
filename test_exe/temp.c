#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <malloc/malloc.h>
#include <string.h>
#include <stdarg.h>

int mx_strlen(const char *s) {
    int i = 0;
    while(s[i])
    	i++;
    return i;
}
char *mx_strcat(char *restrict s1, const char *restrict s2) {
    int len_s1 = mx_strlen(s1);
    int len_s2 = mx_strlen(s2);


    for (int i = len_s1; i < len_s1 + len_s2; i++) {
        s1[i] = *s2;
        s2++;
    }
    s1[len_s1 + len_s2] = '\0';
    return s1;    
}

char *mx_strnew(const int size) {
	if (size < 0)
		return NULL;
    char *str = malloc(size + 1);
    for (int i = 0; i <= size; i++)
    	str[i] = '\0';
    return str;
}
char *mx_strcpy(char *dst, const char *src) {
     int i = 0;
     while (src[i]) {
     	dst[i] = src[i];
     	i++;
     }
     dst[i] = '\0';
     return (char*) dst;
}

char *mx_strdup(const char *str) {
    return mx_strcpy(mx_strnew(mx_strlen(str)), str);
}

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

void *mx_memcpy(void *restrict dst, const void *restrict src, size_t n) {
	char *s1 = (char*) dst;
	char *s2 = (char*) src;

    for (size_t i = 0; i < n; i++)
    	s1[i] = s2[i];

    dst = (void*) s1;
    
    return dst;
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
    if (len < 0)
    	return mx_strdup("\0");
    char *result = mx_strnew(len);
    
    i = 0;
    printf("%d", len);
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
char *mx_strncpy(char *dst, const char *src, int len) {
	int i = 0;
    for (; i < len && src[i]; i++)  
        dst[i] = src[i];
   
    for (; i < len; i++)
    	dst[i] = '\0';
    
    return dst;
}

char *mx_strndup(const char *s1, size_t n) {
    size_t len = mx_strlen(s1);
    if (len < n)
        return mx_strncpy(mx_strnew(len), s1, len);
    else
        return mx_strncpy(mx_strnew(n), s1, n);
}

// void *mx_realloc(void *ptr, size_t size) {
	
// }

char *mx_strjoin(char const *s1, char const *s2) {
    if (s1 == NULL && s2 == NULL)
    	return NULL;

    if (s1 == NULL)
    	return mx_strdup(s2);

    if (s2 == NULL)
    	return mx_strdup(s1);

    // char *result = mx_strnew(mx_strlen(s1) + mx_strlen(s2) - 2);
    // result = mx_strdup(mx_strcat(mx_strdup(s1), s2));
    // return result;
    //return mx_strndup(mx_strcat(mx_strdup(s1), s2), mx_strlen(s1) + mx_strlen(s2));
    return mx_strcat(mx_strdup(s1), s2);
}


int main () {
	char *temp1 = mx_strdup("1234566789011111abc"); 
	char *temp2 = mx_strdup("bc");
	
	char *temp = mx_strjoin(temp1, temp2);
    printf("%s\n", temp);
    printf("%zu\n", malloc_size(temp));
    system("leaks -q a.out");
}

