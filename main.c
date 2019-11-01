#include "inc/libmx.h"
bool cmp(void *s1, void *s2) {
    char *c1 = (char*) s1;
    char *c2 = (char*) s2;
    unsigned long i = 0;
    
    while (c1[i]) {
        if (c1[i] != c2[i])
            break;
        i++;
    }

    if (!c2[i])
        return false;

    return c1[i] > c2[i];
}

void mx_print_list(t_list *list) {
    t_list *temp = list;

    while (temp != NULL) {
        printf("%s\n", temp -> data);
        temp = temp -> next;
    }
}

int main () { 
    /*int size = 5;
    char **arr = (char**)malloc(sizeof(char*) * size);

    arr[0] = mx_strdup("Micelangelo");
    arr[1] = mx_strdup("Donatello");
    arr[2] = mx_strdup("Leonardo");
    arr[3] = mx_strdup("Raphael");
    arr[4] = mx_strdup("Zaz");
    
    mx_printint(mx_quicksort(arr, 0, size - 1));
    mx_printchar('\n');
    
    for (int i = 0; i < size; i++) {
    	mx_printstr(arr[i]);
    	mx_printchar('\n');
    }*/
    //mx_print_unicode(50000);
    //printf("%s", mx_nbr_to_hex(1000));
   
   t_list *head = mx_create_node("123");
   mx_push_back(&head, "456");
   mx_push_front(&head, "789");
   //mx_print_list(head);
   mx_sort_list(head, cmp);
   mx_print_list(head);
   system ("leaks -q a.out");
}
