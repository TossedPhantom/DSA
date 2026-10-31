#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *previous;
    struct node *next;
} node;

typedef struct dcll{
    node *head;
    node *tail;
    int occupied;
} dcll;

void insert(dcll **list, int value){
    if((*list)->occupied == 0){
        node *tmp = malloc(sizeof *tmp);
        if(tmp == NULL){
            printf("Node Allocation Failure #_#\n");
            return;
        }
        tmp->data = value;
        tmp->next = tmp;
        tmp->previous = tmp;
        (*list)->head = tmp;
        (*list)->tail = tmp;
        (*list)->occupied++;
    }
    else{
        node *tmp = malloc(sizeof *tmp);
        if(tmp == NULL){
            printf("Node Allocation Failure #_#\n");
            return;
        }
        tmp->data = value;
        tmp->next = (*list)->head;
        tmp->previous = (*list)->tail;
        (*list)->head->previous = tmp;
        (*list)->tail->next = tmp;
        (*list)->tail = tmp;
        (*list)->occupied++;
    }
}

void delete(dcll **list){
    if((*list)->occupied == 0){
        printf("Bro, the list is already empty ~_~\n");
        return;
    }
    if((*list)->occupied == 1){
        free((*list)->head);
        (*list)->head = NULL;
        (*list)->tail = NULL;
        (*list)->occupied--;
    }
    else{
        node *tmp = (*list)->head;
        (*list)->head = (*list)->head->next;
        (*list)->head->previous = (*list)->tail;
        (*list)->tail->next = (*list)->head;
        free(tmp);
        (*list)->occupied--;
    }
}

void display(dcll *list){
    if(list->occupied == 0){
        printf("List is Empty @_@\n");
        return;
    }
    else{
        node *tmp = list->head;
        do{
            printf("[%p | %d | %p]\n", (void *)tmp->previous, tmp->data, (void *)tmp->next);
            tmp = tmp->next;
        }while(tmp != list->head);
    }
}

void lick(dcll **list){
    if((*list)->occupied == 0){
        (*list)->head = NULL;
        (*list)->tail = NULL;
        free(*list);
        *list = NULL;
    }
    else{
        node *tmp = (*list)->head;
        (*list)->tail->next = NULL;
        (*list)->head->previous = NULL;
        while(tmp != NULL){
            (*list)->head = (*list)->head->next;
            free(tmp);
            tmp = (*list)->head;
        }
        (*list)->head = NULL;
        (*list)->tail = NULL;
        free(*list);
        *list = NULL;
    }
}

char opscan(char *operation){
    printf("Enter operation: ");
    scanf(" %c", operation);
    return *operation;
}

int vscan(int *value){
    printf("Enter value: ");
    scanf("%d", value);
    return *value;
}

int main(){
    dcll *doubly_circular_ll = malloc(sizeof *doubly_circular_ll);
    if(doubly_circular_ll == NULL){
        printf("List Allocation Failure T_T\n");
        return 1;
    }
    doubly_circular_ll->head = NULL;
    doubly_circular_ll->tail = NULL;
    doubly_circular_ll->occupied = 0;
    int value;
    char operation;
    printf("Enter:\ni -> insert elements at rear\nr -> remove element from front\nd -> display elements\nq -> quit\n");

    while(1){
        switch(opscan(&operation)){
            case 'i':
                insert(&doubly_circular_ll, vscan(&value));
                break;
            case 'r':
                delete(&doubly_circular_ll);
                break;
            case 'd':
                display(doubly_circular_ll);
                break;
            case 'q':
                lick(&doubly_circular_ll);
                return 0;
        }
    }
}
