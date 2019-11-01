#include "inc/libmx.h"
bool cmp(void *s1, void *s2) {
    char *c1 = (char*) s1;
    char *c2 = (char*) s2;
    unsigned long i = 0;
    write(1, "1", 1);
    while (c1[i]) {
        if (c1[i] != c2[i])
            break;
        i++;
    }

    if (!c2[i])
        return false;
    write(1, "2", 1);
    return c1[i] > c2[i];
}

void mx_print_list(t_list *list) {
    t_list *temp = list;

    while (temp != NULL) {
        printf("%s\n", temp -> data);
        temp = temp -> next;
    }
}
static void mx_push_index(t_list **list, void *data, int index) {
    if (index <= 0) {
        mx_push_front(list, data);
        return;
    }
    if (index >= mx_list_size(*list)) {
        mx_push_back(list, data);
        return;
    }
    
    t_list *new = mx_create_node(data);
    t_list *last = *list;
    t_list *present = last -> next;
    
    for (int i = 1; i < index; i++) {
        present = present -> next;
        last = last -> next;
    }
    
    last -> next = new;
    new -> next = present;
}


static void mx_pop_index(t_list **list, int index) {
    if (index <= 0) {
        mx_pop_front(list);
        return;
    }
    if (index >= mx_list_size(*list)) {
        mx_pop_back(list);
        return;
    }
    
    t_list *last = *list;
    t_list *present = last -> next;
    
    for (int i = 1; i < index; i++) {
        present = present -> next;
        last = last -> next;
    }

    last -> next = present -> next;
    free(present);
}

static void mx_swap_int(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

static void mx_swap_list(t_list **list, int elem1, int elem2) {
    //write(1, "3", 1);
    if (elem1 == elem2)
        return;
    else if (elem1 > elem2)
        mx_swap_int(&elem1, &elem2); 

    t_list *first = *list;
    t_list *second = *list;
    int index = 0;
 
    
    while (index < elem1) {
        index++;
        first = first -> next;
    }
    
    index = 0;
    while (index < elem2) {
        index++;
        second = second -> next;
    }
    
    mx_push_index(list, second -> data, elem1);    
    mx_push_index(list, first -> data, elem2 + 1);
    
    mx_pop_index(list, elem1 + 1);
    mx_pop_index(list, elem2 + 1);
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
   mx_print_list(head);
   write(1, "4", 1);
   printf("dfg%d\n", mx_list_size(head));
   mx_sort_list(&head, cmp);
   write(1, "4", 1);
   printf("\n");
   mx_print_list(head);
   system ("leaks -q a.out");
}
