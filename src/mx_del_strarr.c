#include "libmx.h"

void mx_del_strarr(char ***arr) {
    free(**arr);
    *arr = NULL;
}
