#include <stdio.h>
#include <stdlib.h>
char *mx_strnew(const int size);
int mx_strlen(const char *s);
char *mx_strstr(const char *haystack, const char *needle);



static int mx_strncmp(const char *s1, const char *s2, int n) {
    int i = 0;
    while (s1[i] && i < n) {
        if (s1[i] != s2[i]) 
            return s1[i] - s2[i];
        i++;
    }
    if (s2[i] && i < n) {
        return s1[i] - s2[i];
    }
    return 0;
}

static int mx_count_substr(const char *str, const char *sub) {
    int counts = 0;
    char *temp = mx_strstr(str, sub);

    while (temp != NULL) { 
    	temp++;
    	temp = mx_strstr(temp, sub);
    	counts++;
    }

    return counts;
}

char *mx_replace_substr(const char *str, const char *sub, const char *replace) {
    if (!str || !sub || !replace)
        return NULL;

    //char *temp = str;
    char *result = mx_strnew(mx_strlen(str) + mx_count_substr(str, sub) * (mx_strlen(replace) - mx_strlen(sub)));
    int k = 0;
    int i = 0;


    while(str[i]) {
        while (mx_strncmp(&str[i], sub, mx_strlen(sub))) {
            result[k] = str[i];
            k++;
            i++;
        }

        i += mx_strlen(sub);
        for (int j = 0; j < mx_strlen(replace); j++) {
            result[k] = replace[j];
            k++;
        }
    }
    

    return result;
}
/*
int main () {
    char *str = "ruUruru turu";
    char *sub = "ruru";
    char *replace = "ru";

    printf("%s\n", mx_replace_substr(str, sub, replace));

}
*/
