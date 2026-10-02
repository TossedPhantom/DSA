#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *link;
} Node;

void enqueue(Node **front, Node **rear, int value){
    Node *tmp = malloc(sizeof *tmp);
    if(tmp == NULL){
        printf("Node Allocation Failure");
        return;
    }
    tmp->data = value;
    tmp->link = NULL;
    if(*rear == NULL){
        *rear = tmp;
        *front = tmp;
    }
    else{
        (*rear)->link = tmp;
        *rear = tmp;
    }
}

void dequeue(Node **front, Node **rear){
    if(*front == NULL){
        printf("Queue Underflow @_@\n");
        return;
    }
    else if(*front == *rear){
        free(*front);
        *front = NULL;
        *rear = NULL;
    }
    else{
        Node *tmp = *front;
        *front = (*front)->link;
        free(tmp);
    }
}

void display(Node *front){
    if(front == NULL){
        printf("Empty Queue -_-\n");
        return;
    }
    Node *tmp = front;
    while(tmp != NULL){
        printf("%d ", tmp->data);
        tmp = tmp->link;
    }
    printf("\n");
}

void lick(Node **front, Node **rear){
    while(*front != NULL){
        if(*front == *rear){
            free(*front);
            *front = NULL;
            *rear = NULL;
        }
        else{
            Node *tmp = *front;
            *front = (*front)->link;
            free(tmp);
        }
    }
}

int vscan(int *target){
    printf("Enter value to enqueue: ");
    scanf("%d", target);
    return *target;
}

char opscan(char *operation){
    printf("Enter operation: ");
    scanf(" %c", operation);
    return *operation;
}

int main(){
    Node *front = NULL;
    Node *rear = NULL;
    int target;
    char operation;

    printf("Enter:\ne-> Enqueue\nd-> Dequeue\np-> Print Queue\nq-> Quit\n");
    while(1){
        switch(opscan(&operation)){
            case 'e':
                enqueue(&front, &rear, vscan(&target));
                break;
            case 'd':
                dequeue(&front, &rear);
                break;
            case 'p':
                display(front);
                break;
            case 'q':
                lick(&front, &rear);
                return 0;
        }
    }
}
