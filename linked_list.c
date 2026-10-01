#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *link;
};

int main(){
    //Initialise a linked list T_T
    struct Node *head = malloc(sizeof* head);
    head->link = NULL;
    head->data = 0;
    struct Node *pointer = head;
    for(int i = 1; i < 7; i++){
        struct Node *newnode = malloc(sizeof* newnode);
        newnode->data = i;
        pointer->link = newnode;
        newnode->link = NULL;
        pointer = newnode;
    }

    //Print its elements
    pointer = head;
    while(pointer != NULL){
        printf("%d\n", pointer->data);
        pointer = pointer->link;
    }

    //free linked list
    pointer = head;
    while(pointer != NULL){
        struct Node *next = pointer->link;
        free(pointer);
        pointer = next;
    }

    return 0;
}
