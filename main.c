#include "inc/libmx.h"
#include <stdio.h>

int main() {
	char file[] = "test.txt";
    char str1[] = "1234";
    char *str2 = NULL;

    mx_write_to_file(file, str1, 'a');
    system("leaks -q a.out");
    return 0;
}
