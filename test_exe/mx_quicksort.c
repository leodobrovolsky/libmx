#include <unistd.h>
#include <stdio.h>

int mx_strcmp(const char *s1, const char *s2) {
    int i = 0;
    while(s1[i]) {
        if (s1[i] != s2[i])
            return s1[i] - s2[i];
        i++;
    }

    if (s2[i])
        return s1[i] - s2[i];
    return 0;
}

static void mx_swap_str(char **s1, char **s2) {
    char *temp = NULL;
    temp = *s1;
    *s1 = *s2;
    *s2 = temp;
}


int mx_quicksort(char **arr, int left, int right) {
    if (!arr)
        return -1;

    int shift  = 0;
    int indifier = 1;
    int mid = (left + right) / 2;
    int begin = left;
    int end = right;
    
    while (indifier > 0) {
        mid = (left + right) / 2;
        begin = left;
        end = right;
        indifier = 0;
        while(mx_strcmp(arr[begin], arr[mid]) < 0)
            begin++;

        while (mx_strcmp(arr[end], arr[mid]) > 0) 
            end--;

        if (begin < end) {
            indifier++;
            shift++;
            mx_swap_str(&arr[begin], &arr[end]);
            begin++;
            end--;
        
            
        if (end > left)  {
            //mx_quicksort(arr, left, end);
            right = end;
        }

        if (begin < right) {
            //mx_quicksort(arr, begin, right);
            left = begin;
        }
        }
    }
    return shift;
}

int main(){
    int size = 5;
    char *arr[] = {"Michelangelo","Donatello","Leonardo","Raphael", "Azazello"};
    printf("%d\n", mx_quicksort(arr, 0, size - 1));
    for (int i = 0; i < size; i++)
        printf("%s\n", arr[i]);
}

