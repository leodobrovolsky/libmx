#include <stdlib.h>
char *mx_strdup(const char *str);
char *mx_strcat(char *s1, const char *s2);
int mx_strlen(const char *str);

char *mx_strjoin(char const *s1, char const *s2) {
    if (s1 == NULL && s2 == NULL)
    	return NULL;

    if (s1 == NULL)
    	return mx_strdup(s2);

    if (s2 == NULL)
    	return mx_strdup(s1);


    return mx_strcat(mx_strdup(s1), s2);
}

