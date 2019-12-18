#include "inc/libmx.h"
#include <stdio.h>

int main() {
    char str[] = "1234";
    mx_print_format_str(str, 'c', '*', 6);
    return 0;
}
