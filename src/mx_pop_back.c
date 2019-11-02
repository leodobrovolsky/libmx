#include "libmx.h"

void mx_pop_back(t_list **head) {
    if (*head == NULL)
        return;
    t_list *last = *head;
    t_list *present = *head;
    
    while (present -> next != NULL) {
        last = present;
        present = present -> next;
    }
    last -> next = NULL;
    free(present -> data);
    free(present);
}
