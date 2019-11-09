#include "libmx.h"

void mx_swap_list(t_list **list, int elem1, int elem2) {
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
