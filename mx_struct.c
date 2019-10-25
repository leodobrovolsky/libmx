#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct  s_list {
    void  *data;
    struct s_list *next;
}  t_list;
 
t_list  *mx_create_node(void *data);
void mx_push_front(t_list **list, void *data);
void mx_push_back(t_list **list, void *data);
void mx_pop_front(t_list **head);
void mx_pop_back(t_list **head);

bool mx_cmp(char *s1, char *s2) {
    int i = 0;
    while(s1[i]) {
        if (s1[i] != s2[i]) {
            if (s1[i] - s2[i] > 0)
                return true;
            else
                return false;
        }
        i++;
    }

    if (s2[i]) {
        if (s1[i] - s2[i] > 0)
            return true;
        else
            return false;
    }
    return false;
}

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
    if (*list == NULL) {
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


void mx_push_index(t_list **list, void *data, int index) {
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


void mx_pop_index(t_list **list, int index) {
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

void mx_print_list(t_list *list) {
    t_list *temp = list;
    
    while (temp != NULL) {
        printf("%s\n", temp -> data);
        temp = temp -> next;
    }
}

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

void *mx_get_data(t_list *list, int index) {
    t_list *temp = list;
    
    for (int i = 0; i < index; i++)
        temp = temp -> next;
    
    return temp -> data;
}

t_list *mx_sort_list(t_list *lst, bool (*cmp)(char *, char *)) {
    int min_elem = 0;
    int size = mx_list_size(lst);

    if (size <= 1)
        return lst;
    
    for (int i = 0; i < size; i++) {
        min_elem = i;
        for (int j = i; j < size; j++)
            if (cmp(mx_get_data(lst, min_elem), mx_get_data(lst, j)))
                min_elem = j;
        if (min_elem > i)
            mx_swap_list(&lst, i, min_elem);
    }

    return lst;  
}
/*
int main () {
    char *data1 = "123";
    char *data2 = "456";
    char *data3 = "789";
    char *data4 = "0";
    t_list *go = NULL;
    t_list *head = mx_create_node(data3);

    //mx_push_front(&head, "456");
    mx_push_back(&head, data2);
    mx_push_back(&head, data1);
    mx_push_back(&head, data4);
    mx_print_list(head);
    head = mx_sort_list(head, mx_cmp);
    mx_print_list(head);
    printf("%d\n", mx_list_size(go));
}*/

