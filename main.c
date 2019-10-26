#include "inc/libmx.h"

int main () { 
    char *input;
    int val_int = 0;
    int *arr_int = NULL;
    int **marr_int = NULL;
    char val_char = '\0';
    char *str = NULL;
    char **arr_str = NULL;
    //char **arr_func = (char**) malloc(sizeof(char*) * 56);
    char **arr_func = {mx_printchar, mx_print_unicode, mx_printstr, mx_print_strarr, mx_printint, mx_pow, mx_sqrt, mx_nbr_to_hex, mx_hex_to_nbr, mx_itoa, mx_foreach, mx_binary_search, mx_bubble_sort, mx_quicksort, mx_strlen, mx_swap_char, mx_str_reverse, mx_strdel,  mx_del_strarr, mx_get_char_index, mx_strdup, mx_strndup, mx_strcpy, mx_strncpy, mx_strcmp, mx_strcat, mx_strstr, mx_get_substr_index, mx_count_substr, mx_count_words, mx_strnew, mx_strtrim, mx_del_extra_spaces, mx_strsplit, mx_strjoin, mx_file_to_str, mx_read_line, mx_replace_substr, mx_memset, mx_memcpy, mx_memccpy, mx_memcmp, mx_memchr, mx_memrchr, mx_memmem, mx_memmove, mx_realloc, mx_create_node, mx_push_front, mx_push_back, mx_pop_front, mx_pop_back, mx_list_size, mx_sort_list};

    while (1) {
        printf("Input function: ");
        scanf("%s", input);
        printf("%s\n", input);

        if (!mx_strcmp(input, "q"))
        	break;

        while (1) {
        	printf("Input parameters: ");
            scanf("%s", input);
            if (!mx_strcmp(input, "q"))
            	break;
        }
    }
}
