#include "libmx.h"

int mx_quicksort(char **arr, int left, int right) {
    if (!arr)
        return -1;

    int shift = 0;
    int mid = (left + right) / 2;
    int begin = left;
    int end = right;   

    while(mx_strlen(arr[begin]) - mx_strlen(arr[mid]) < 0)
        begin++;

    while (mx_strlen(arr[end]) - mx_strlen(arr[mid]) > 0) 
        end--;

    if (begin <= end) {  
        if (mx_strlen(arr[begin]) != mx_strlen(arr[end])) {
            shift++;
            mx_swap_str(&arr[begin], &arr[end]);
        }
        begin++;
        end--;
    }
        
    if (end > left) 
        shift += mx_quicksort(arr, left, end);

    if (begin < right) 
        shift += mx_quicksort(arr, begin, right);

    return shift;
}

