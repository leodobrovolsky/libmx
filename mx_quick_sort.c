#include <stdio.h>
#include <unistd.h>
int mx_strcmp(const char *s1, const char *s2);

static void mx_swap_str(char **s1, char **s2) {
    char *temp = NULL;
    temp = *s1;
    *s1 = *s2;
    *s2 = temp;
}


int mx_quick_sort(char **arr, int left, int right) {
    if (!arr)
        return -1;
    int shift = 0;
    int mid = (left + right) / 2;
    int begin = left;
    int end = right;

    while (begin <= end) {
        while(mx_strcmp(arr[begin], arr[mid]) < 0)
            begin++;

        while (mx_strcmp(arr[end], arr[mid]) > 0) 
            end--;

        if (begin <= end) {
            shift += 1;
            mx_swap_str(&arr[begin], &arr[end]);
           
       
            begin++;
            end--;
        }
    }

    if (end > left)
        mx_quick_sort(arr, left, end);
    if (begin < right)
        mx_quick_sort(arr, begin, right);
    
    return shift;
}

int main () {
    char *arr[] = {"Michelangelo", "Donatello", "Leonardo", "Raphael"};
    printf("%d\n", mx_quick_sort(arr, 0, 3)); //returns 2
    //mx_swap_char(&arr[0], &arr[1]);
    for (int i = 0; i < 4; i++)
        printf("%s\n", arr[i]);
 
}
