#include "inc/libmx.h"
#include <time.h>
#include <string.h>
static void mx_swap(char **arr, int i, int j, int *swaps){
    char *c;

    if (mx_strlen(arr[i]) != mx_strlen(arr[j])){
     c = arr[i];
     arr[i] = arr[j];
     arr[j] = c;
        (*swaps)++;
    }
}

static void mx_add_part(t_list **list, int l, int r){
    if (r > l){
        int *node = malloc(sizeof(int) * 2);
        node[0] = l;
        node[1] = r;
        mx_push_front(list, node);
    }
}

int mx_quicksort_valera(char **arr, int left, int right) {
    int swaps = 0, pivot, l, r;
    t_list *list = NULL;

    if (!arr)
        return -1;
    mx_add_part(&list, left, right);
    while (list) {
        l = (left = ((int *)list->data)[0]);
        r = (right = ((int *)list->data)[1]);
        //free(list->data);
        mx_pop_front(&list);
        pivot = mx_strlen(arr[left + ((right - left) / 2)]);
        while (l <= r){
         while (mx_strlen(arr[l]) < pivot &&  ++l <= right);
         while (mx_strlen(arr[r]) > pivot && --r >= left);
         if (l <= r)
                mx_swap(arr, l++, r--, &swaps);
        }
        mx_add_part(&list, l, right);
        mx_add_part(&list, left, r);
    }
    return swaps;
}


int mx_quicksort_andriy(char **arr, int left, int right) {
    int count = 0;
    if(arr == NULL) return -1;
    if(left < right)
    {
        int low = left, high = right;
        char *middle = arr[(low + high) / 2];
        while(low <= high)
        {
            while(mx_strlen(arr[low]) < mx_strlen(middle)) low++;
            while(mx_strlen(arr[high]) > mx_strlen(middle)) high--;
            if(low <= high)
            {
                if(arr[low] != arr[high]
                    && mx_strlen(arr[low]) != mx_strlen(arr[high])) count++;
                mx_swap_str(&arr[low],&arr[high]);
                low++;
                high--;
            }
        }
        count += mx_quicksort_andriy(arr, left, high);
        count += mx_quicksort_andriy(arr, low, right);
    }
    return count;
}

// void mx_swap_my(char ***arr, int low, int high) {
//     char *temp = NULL;

//     while ()

// }


int mx_quicksort_my(char **arr, int left, int right) {
    int count = 0;
    if(arr == NULL) return -1;
    if(left < right)
    {
        int low = left, high = right;
        char *middle = arr[(low + high) / 2];
        while(low <= high)
        {
            while(mx_strlen(arr[low]) < mx_strlen(middle)) low++;
            while(mx_strlen(arr[high]) > mx_strlen(middle)) high--;
            if(low <= high)
            {
                if(arr[low] != arr[high]
                    && mx_strlen(arr[low]) != mx_strlen(arr[high])) count++;
                mx_swap_str(&arr[low],&arr[high]);
                low++;
                high--;
            }
        }
        count += mx_quicksort_andriy(arr, left, high);
        count += mx_quicksort_andriy(arr, low, right);
    }
    return count;
}



bool mx_write_to_file(char *str, int fd) {
    if (fd < 3 || !str) 
        return false;
    
    int ind = write(fd, str, mx_strlen(str));
    
    if (ind < 0) 
        return false;
    else
        return true;
}

int main () {
    // char *ptr1 = NULL;
    // char *ptr2 = NULL;
    // char *ptr3 = mx_realloc(ptr1, 100);
    // char *ptr4 = realloc(ptr2, 100);

    // printf(":%s:\n", ptr1);
    // printf("%zu\n", malloc_size(ptr1));
    // printf("%s\n", ptr2);
    // printf("%zu\n", malloc_size(ptr2));

    // printf("%s\n", ptr3);
    // printf("%zu\n", malloc_size(ptr3));
    // printf("%s\n", ptr4);
    // printf("%zu\n", malloc_size(ptr4));
    const int MAX_LEN = 100;
    const int MAX_INT = 2147483647;
    srand(time(NULL)); 
    int len = rand() % MAX_LEN;
    char *str = mx_strnew(len);
    int index = 0;

    for (int i = 0; i < len; i++) {
        index = rand() % 10;
        if (index > 2)
            str[i] = 65 + rand() % 26;
        else if (str[i - 1] != ' ' && i != 0)
            str[i] = ' ';
        else
            str[i] = 65 + rand() % 26;
    }

    int fp = open("test", O_WRONLY);
    int ind = mx_write_to_file(str, fp);
    
    if (ind)
        printf("Write OK\n");
    else
        printf("Write Error\n");
    close(fp);


    char **arr1 = strsplit(str, ' ');
    char **arr2 = strsplit(str, ' ');

    int size1 = 0;
    int size2 = 0;

    while(arr1[size1])
        size1++;
   
    while(arr2[size2])
        size2++;
   
    printf("size %d %d\n", size1, size2);
    printf("str .%s.\n", str);
    for (int i = 0; i < size1; i++) {
        if(mx_strcmp(arr1[i], arr2[i])) 
            printf("Error: %d: .%s. : .%s.\n", i, arr1[i], arr2[i]);
    }

    int sort1 = mx_quicksort_valera(arr1, 0, size1 - 1);
    int sort2 = mx_quicksort_valera(arr2, 0, size2 - 1);
 
    // for (int i = 0; i < size; i++)
    //     printf("%s  %s\n", arr1[i], arr2[i]);
    
    printf("my %d\n", sort1);
    printf("andriy %d\n", sort2);
    

    // int res;
    // char *str = NULL;
    // int fd = open("test.txt", O_RDONLY);

    // res = mx_read_line(&str, 20, 'f', fd);
    // printf("res %s %d\n", str, res); 

    // res = mx_read_line(&str, 35, 't', fd);
    // printf("res %s %d\n", str, res); 

    // res = mx_read_line(&str, 4, '.', fd);
    // printf("res %s %d\n", str, res); 
    // mx_strdel(&str);
    // close(fd);


    // const int MAX_LEN = 500000;
    // const int MAX_INT = 2147483647;
    // srand(time(NULL)); 
    // int len = rand() % MAX_LEN;
    // char *str = mx_strnew(len);

    // for (int i = 0; i < len; i++)
    //     str[i] = 65 + rand() % 26;

    // int fp = open("test", O_WRONLY);
    // int ind = mx_write_to_file(str, fp);
    
    // if (ind)
    //     printf("Write OK\n");
    // else
    //     printf("Write Error\n");
    // close(fp);
    
    // printf("str = %s\nlen = %d\n", str, len);
    
    // int delim = 65 + rand() % 26;
    // int len_str_new = 0;
    // int buf_size = rand() % 10 + 1;
    // char *str_new = mx_strchr(str, str[0]);
    // char *func_str = NULL;
    // int nbytes = 0;
    // int fd = open ("test", O_RDONLY);

    // while (str_new) {
    //     ind = 0;
    //     buf_size = rand() % 10 + 1;
    //     len = mx_strlen(str);
    //     str_new = mx_strchr(str, delim);
    //     if (!str_new)
    //         ind++;
    //     printf("buf_size %d %c\n", buf_size, delim);
    //     if (ind < 2) {
    //         nbytes = mx_read_line(&func_str, buf_size, delim, fd);
    //         if (ind == 0)
    //             len_str_new = len - mx_strlen(str_new);
    //         else 
    //             len_str_new = mx_strlen(str);
    //         if (mx_strcmp(func_str, mx_strndup(str, len_str_new))) {
    //             printf("Error:\ndelim: %c\nUser %s\nOrac %s\n", delim, func_str, mx_strndup(str, len_str_new));
    //             break;
    //         }
    //         else if (nbytes != len_str_new) {
    //             printf("Error:\ndelim: %c\nUser %d\nOrac %d\n", delim, nbytes, len_str_new);
    //             break;               
    //         }
    //         else
    //         	printf("OK:\ndelim: %c\nUser %s\nOrac %s\n", delim, func_str, mx_strndup(str, len_str_new));
    //         if (ind > 0)
    //             break;
    //         str = str_new + 1;
    //         delim = 65 + rand() % 26;
    //     }
    // }
    // close(fd);



    //system("leaks -q a.out");
    return 0;
}
