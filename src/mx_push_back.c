#include "libmx.h"

void mx_push_back(t_list **list, void *data){
    t_list *back = mx_create_node(data);
    if (*list == NULL) {
        *list = back;
        return;
    }
    t_list *temp = *list;
    while (temp -> next != NULL) 
        temp = temp -> next;
    temp -> next = back;
}
