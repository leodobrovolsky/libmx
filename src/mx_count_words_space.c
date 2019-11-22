#include "libmx.h"

int mx_count_words_space(const char *str) {
    if (!str)
        return -1;
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
