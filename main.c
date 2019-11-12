#include "inc/libmx.h"

int main () {

    printf("%s", mx_file_to_str("test"));
    // char *str = mx_strdup("123");
    // char *str_new = NULL;
    // char *buf = mx_strdup("4");

    // str_new = mx_strjoin(str, buf);
    // mx_strdel(&str);
    // mx_strdel(&buf);
    // printf("%s\n", str_new);

    //system ("leaks -q a.out");
    return 0;
}
