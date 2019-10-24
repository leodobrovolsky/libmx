#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct  s_list {
    void  *data;
    struct s_list *next;
}  t_list;
 
t_list  *mx_create_node(void *data);
void mx_push_front(t_list **list, void *data);
void mx_push_back(t_list **list, void *data);
void mx_pop_front(t_list **head);
void mx_pop_back(t_list **head);


t_list  *mx_create_node(void *data) {
    t_list *new = malloc(sizeof(t_list));
    new -> data = data;
    new -> next = NULL;
    return new;
}

void mx_push_front(t_list **list, void *data) {
    t_list *front = mx_create_node(data);
    if (*list == NULL) {
        *list = front;
        return;
    }
    front -> next = *list;
    *list = front;
}

void mx_push_back(t_list **list, void *data){
    t_list *back = mx_create_node(data);
    if (*list == NULL)
        *list = back;
        return;
    }
    t_list *temp = *list;
    while (temp -> next != NULL) 
        temp = temp -> next;
    temp -> next = back;
}


void mx_pop_front(t_list **head){
    if (*head == NULL)
        return;
    t_list *temp = *head;
    *head = temp -> next;
    free(temp);
}
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
    free(present);
}

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

t_list *mx_sort_list(t_list *lst, bool (*cmp)(void *, void *)) {
    int size = mx_list_size(lst);
    if (size <= 1)
        return lst;
    t_list *first = NULL;
    t_list *second = NULL;
    
    for (int i = 0; i < size; i++) {
         *first = lst;
         *second = first -> next;
        for (int j = 1; j < size - i; j++) {
            if (cmp(first -> data, second -> data)) {
                
            }
            first = first -> next;
            second = first -> next;
        }
    }
    
    return lst;
}

int main () {
    char *data1 = "123";
    char *data2 = "456";
    char *data3 = "789";
    
    t_list *head = mx_create_node(data1);
    
    t_list *last_node = head;
    t_list *present_node = head;
    
    mx_push_front(&head, "456");
    mx_push_back(&head, "789");
    mx_pop_front(&head);
    mx_pop_back(&head);
}
