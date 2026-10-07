#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *previous;
    struct Node *next;
}   Node;

void insert(Node **head, int data){
    Node *newnode = malloc(sizeof **head);
    if(newnode == NULL){
        printf("Node Allocation Failure #_#\n");
        return;
    }
    newnode->data = data;
    newnode->previous = NULL;
    newnode->next = *head;
    if(*head != NULL) (*head)->previous = newnode;
    *head = newnode;
}

void delete(Node **head){
    if(*head == NULL){
        printf("Nothing to delete in Node O_O\n");
        return;
    }
    Node *tmp = (*head)->next;
    if(tmp != NULL) tmp->previous = NULL;
    free(*head);
    *head = tmp;
}

void display(Node *head){
    if(head == NULL){
        printf("Empty Doubly Linked List -_-\n");
        return;
    }
    Node *tmp = head;
    while(tmp != NULL){
        printf("[%-14p | %d | %-14p]\n", (void *)tmp->previous, tmp->data, (void *)tmp->next);
        tmp = tmp->next;
    }
}

void lick(Node **head){
    if(*head == NULL) return;
    while(*head != NULL){
        Node *tmp = (*head)->next;
        free(*head);
        *head = tmp;
    }
}

int vscan(int *target){
    printf("Enter value to append to beginning: ");
    scanf("%d", target);
    return *target;
}

char opscan(char *operation){
    printf("Enter operation: ");
    scanf(" %c", operation);
    return *operation;
}

int main(){
    Node *head = NULL;
    int target;
    char operation;

    printf("Enter:\ni: insert element at beginning\nr: remove element from beginning\nd: display element at beginning\nq: quit\n");
    while(1){
        switch(opscan(&operation)){
            case 'i':
                insert(&head, vscan(&target));
                break;
            case 'r':
                delete(&head);
                break;
            case 'd':
                display(head);
                break;
            case 'q':
                lick(&head);
                return 0;
            default:
                printf("Invalid Operation\n");
                break;
        }
    }

}
