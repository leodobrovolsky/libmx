#include "libmx.h"

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


static void *mx_get_data(t_list *list, int index) {
    t_list *temp = list;
    
    for (int i = 0; i < index; i++)
        temp = temp -> next;
    
    return temp -> data;
}


static void mx_swap_list(t_list **list, int elem1, int elem2) {
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


t_list *mx_sort_list(t_list *list, bool (*cmp)(void *, void *)) {
    int min_elem = 0;
    int size = mx_list_size(list);
    write(1, "4", 1);
    if (size <= 1)
        return list;
    
    for (int i = 0; i < size; i++) {
        min_elem = i;
        for (int j = i; j < size; j++)
            if (cmp(mx_get_data(list, min_elem), mx_get_data(list, j)))
                min_elem = j;
        if (min_elem > i)
            mx_swap_list(&list, i, min_elem);
    }

    return list;  
}
