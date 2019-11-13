#include "inc/libmx.h"

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
    // char **arr = mx_strsplit(str, ' ');
    // char **arr1 = mx_strsplit(str, ' ');
    // char **arr2 = mx_strsplit(str, ' ');
    // int size = 0;

    // while(arr1[size])
    //     size++;


    // printf("andriy %d\n", mx_quicksort_andriy(arr1, 0, size - 1));
    // printf("my %d\n", mx_quicksort(arr2, 0, size - 1));
    // printf("size %d\n", size);
 
    // for (int i = 0; i < size; i++)
    //     printf("%s  %s  %s\n", arr[i], arr1[i], arr2[i]);


    return 0;
}
