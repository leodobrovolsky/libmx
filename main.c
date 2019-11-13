#include "inc/libmx.h"


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
    char *str = mx_strnew(20);
    int fd = open("test.txt", O_RDONLY);
    
    res = mx_read_line(&str, 20, 'f', fd);
    printf("res %s %d\n", str, res); 

    res = mx_read_line(&str, 35, 't', fd);
    printf("res %s %d\n", str, res); 
    
    res = mx_read_line(&str, 4, '.', fd);
    printf("res %s %d\n", str, res); 
    
    close(fd);


    // int fd = open("test", O_RDONLY);
    // char buf[4];
    // int r = read(fd, buf, 2);

    // r = read(fd, buf, 1);

    // printf("%d  %s\n", r, buf);

    // close(fd);

    //system("leaks -q a.out");
    return 0;
}
