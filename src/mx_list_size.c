#include "libmx.h"

int mx_list_size(t_list *list) {
    if (list == NULL)
        return 0;
        
    t_list *temp = list;
    int size = 1;
    
    while (temp -> next != NULL) {
        size++;
        temp = temp -> next;
    }
    return size;
}
