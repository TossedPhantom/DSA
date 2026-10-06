#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *link;
} Node;

void insert(Node **head, Node **last, int data){
    Node *newnode = malloc(sizeof **head);
    if(newnode == NULL){
        printf("Node Allocation Failure #_#\n");
        return;
    }
    newnode->data = data;
    if(*head == NULL){
        *head = newnode;
        *last = newnode;
    }
    else{
        (*last)->link = newnode;
        *last = newnode;
    }
    (*last)->link = *head;
}

void delete(Node **head, Node **last){
    if(*head == NULL){
        printf("No Node present to delete -_-\n");
        return;
    }
    if(*head == *last){
        free(*head);
        *head = NULL;
        *last = NULL;
    }
    else{
        Node *tmp = *head;
        *head = (*head)->link;
        (*last)->link = *head;
        free(tmp);
    }
}

void display(Node *head, Node *last){
    if(head == NULL) printf("Empty Circular Linked List\n");
    else{
        Node *tmp = head;
        do{
            if(tmp != last) printf("[%d | %p]->", tmp->data, tmp->link);
            else printf("[%d | %p]", tmp->data, tmp->link);
            tmp = tmp->link;
        }while(tmp != head);
        printf("\n");
    }
}

void lick(Node **head, Node **last){
    if(*head == NULL) return;
    else{
        (*last)->link = NULL;
        while(*head != NULL){
            Node *next = (*head)->link;
            free(*head);
            *head = next;
        }
        *last = NULL;
    }
}

int vscan(int *target){
    printf("Enter integer value to input: ");
    scanf("%d", target);
    return *target;
}

char opscan(char *operation){
    printf("Enter operation: ");
    scanf(" %c", operation);
    return *operation;
}

int main(){
    Node *head = NULL, *last = NULL;
    int target;
    char operation;
    printf("Enter: \ni-> Insert an element to the end\nr-> remove an element from the front\nd-> display the circular linked list\nq-> quit\n");

    while(1){
        switch(opscan(&operation)){
            case 'i':
                insert(&head, &last, vscan(&target));
                break;
            case 'r':
                delete(&head, &last);
                break;
            case 'd':
                display(head, last);
                break;
            case 'q':
                lick(&head, &last);
                return 0;
            default:
                printf("Invalid Input\n");
                break;
        }
    }

}
