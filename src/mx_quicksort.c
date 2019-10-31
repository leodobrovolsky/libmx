#include "libmx.h"

static void mx_swap_str(char **s1, char **s2) {
    char *temp = NULL;
    temp = *s1;
    *s1 = *s2;
    *s2 = temp;
}


int mx_quicksort(char **arr, int left, int right) {
    if (!arr)
        return -1;

    static int shift  = 0;
    int mid = (left + right) / 2;
    int begin = left;
    int end = right;   

    while(mx_strlen(arr[begin]) - mx_strlen(arr[mid]) < 0)
        begin++;

    while (mx_strlen(arr[end]) - mx_strlen(arr[mid]) > 0) 
        end--;

    if (begin <= end) {  
        shift++;
        mx_swap_str(&arr[begin], &arr[end]);
        begin++;
        end--;
    }
        
    if (end > left) 
        mx_quicksort(arr, left, end);

    if (begin < right) 
        mx_quicksort(arr, begin, right);

    return shift;
}

