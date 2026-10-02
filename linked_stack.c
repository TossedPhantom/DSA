#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *link;
};

void push(struct Node **head, int value){
    struct Node *tmp = malloc(sizeof **head);
    if(tmp == NULL){
        printf("Node Allocation Failure *_*\n");
        return;
    }
    tmp->data = value;
    tmp->link = *head;
    *head = tmp;
}

void pop(struct Node **head){
    if(*head == NULL){
        printf("Stack Underflow @_@\n");
        return;
    }
    else{
        struct Node *tmp = (*head)->link;
        free(*head);
        *head = tmp;
    }
}

void display(struct Node *head){
    if(head == NULL){
        printf("Empty Stack -_-\n");
        return;
    }
    struct Node *pointer = head;
    while(pointer != NULL){
        printf("%d\n", pointer->data);
        pointer = pointer->link;
    }
}

int vscan(int *target){
    printf("Enter data to push: ");
    scanf("%d", target);
    return *target;
}

char opscan(char *operation){
    printf("Enter operation: ");
    scanf(" %c", operation);
    return *operation;
}

void lick(struct Node **head){
    while(*head != NULL){
        struct Node *pointer = (*head)->link;
        free(*head);
        *head = pointer;
    }
}

int main(){
    struct Node *head = NULL;
    int target;
    char operation;

    while(1){
        switch(opscan(&operation)){
            case 'p':
                push(&head, vscan(&target));
                break;
            case 'o':
                pop(&head);
                break;
            case 'd':
                display(head);
                break;
            case 'q':
                lick(&head);
                return 0;
        }
    }

}
