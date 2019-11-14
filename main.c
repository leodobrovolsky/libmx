#include "inc/libmx.h"
#include <time.h>

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


bool mx_write_to_file(char *str, int fd) {
    if (fd < 3 || !str) 
        return false;
    
    int ind = write(fd, str, mx_strlen(str));
    
    if (ind < 0) 
        return false;
    else
        return true;
}

int mx_read_lin(char **lineptr, int buf_size, char delim, const int fd) {
    static char *remainder = NULL;
 
    char *buf = mx_strnew(buf_size);
    
    int bytes = 0;
    int delim_index = -1;
    char *tmp_s = NULL;
    char *tmp = NULL;

    if (remainder)
        tmp_s = mx_strdup(remainder);
   
    while ((bytes = read(fd, buf, buf_size)) >= 0) {
        buf[bytes] = '\0';
        tmp = mx_strjoin(tmp_s, buf);
        mx_strdel(&tmp_s);
        tmp_s = mx_strdup(tmp);
        mx_strdel(&tmp);
        delim_index = mx_get_char_index(tmp_s, delim);
        if (delim_index != -1) {
            tmp_s[delim_index] = '\0';
            if (remainder) {
                mx_strdel(&remainder);
            }
            remainder = mx_strdup(tmp_s + delim_index + 1);
            break;
        }
        if (bytes == 0) {
            if (remainder) {
                mx_strdel(&remainder);
            }
            break;
        }
    }
    if (bytes == -1) {
        return -1;
    }
    *lineptr = mx_strdup(tmp_s);
    mx_strdel(&tmp_s);
    mx_strdel(&buf);
    return mx_strlen(*lineptr);
}


int main () {
    // char *str = mx_file_to_str("test");
    // char **arr1 = mx_strsplit(str, ' ');
    // char **arr2 = mx_strsplit(str, ' ');
    // int size = 0;

    // while(arr1[size])
    //     size++;


    // printf("valera %d\n", mx_quicksort_valera(arr1, 0, size - 1));
    // printf("andriy %d\n", mx_quicksort_andriy(arr2, 0, size - 1));
    // printf("size %d\n", size);
 
    // for (int i = 0; i < size; i++)
    //     printf("%s  %s\n", arr1[i], arr2[i]);


    int res;
    char *str = NULL;
    int fd = open("test", O_RDONLY);
    
    res = mx_read_lin(&str, 20, 'F', fd);
    printf("res %s %d\n", str, res); 
    mx_strdel(&str);
    res = mx_read_lin(&str, 35, 'T', fd);
    printf("res %s %d\n", str, res); 
    mx_strdel(&str);
    res = mx_read_lin(&str, 4, 'D', fd);
    printf("res %s %d\n", str, res); 
    mx_strdel(&str);
    close(fd);


    // const int MAX_LEN = 10000;
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
    // int buf_size = rand() % (MAX_INT / 10000);
    // char *str_new = mx_strchr(str, str[0]);
    // char *func_str = NULL;
    // int nbytes = 0;
    // int fd = open ("test", O_RDONLY);

    // while (str_new) {
    //     buf_size = rand() % len;
    //     len = mx_strlen(str);
    //     str_new = mx_strchr(str, delim);
    //     //printf("buf_size %d %c\n", buf_size, delim);
    //     if (str_new) {
    //         nbytes = mx_read_lin(&func_str, buf_size, delim, fd);
    //         len_str_new = len - mx_strlen(str_new);
    //         if (mx_strcmp(func_str, mx_strndup(str, len_str_new))) {
    //             printf("Error:\ndelim: %c\nUser %s\nOrac %s\n", delim, func_str, mx_strndup(str, len_str_new));
    //             break;
    //         }
    //         else if (nbytes != len_str_new) {
    //             printf("Error:\ndelim: %c\nUser %d\nOrac %d\n", delim, nbytes, len_str_new);
    //             break;               
    //         }
    //         else
    //         	printf("OK\n");
    //         str = str_new + 1;
    //         delim = 65 + rand() % 26;
    //     }
    // }
    // close(fd);


    system("leaks -q a.out");
    return 0;
}
