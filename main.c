#include "inc/libmx.h"

int main () {
    char *str = mx_strdup("1234567890");
    mx_memmove (&str[4], &str[3], 3);

   // Вывод массива src на консоль
    printf ("str new: %s\n", str);
    return 0;
}
