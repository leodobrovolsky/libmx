#include <stdlib.h>
char *mx_strstr(const char *s1, const char *s2);

int mx_count_substr(const char *str, const char *sub) {
    int counts = 0;

    if (!str || !sub)
        return -2;

    char *temp = mx_strstr(str, sub);
    while (temp != NULL) { 
    	temp++;
    	temp = mx_strstr(temp, sub);
    	counts++;
    }

    return counts;
}
