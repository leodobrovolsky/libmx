#include "libmx.h"

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

