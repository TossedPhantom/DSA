#include <stdio.h>

int main(){
    int arrsize = 7, arr[arrsize], front = -1, rear = -1, element;
    char operation;
    while(1){
        printf("Enter operation: ");
        scanf(" %c", &operation);
        if(operation == 'e'){
            if(rear == arrsize - 1){
                printf("Queue overflow\n");
                continue;
            }
            printf("Enter element: ");
            scanf("%d", &element);
            if(front == -1){
                front++;
                arr[++rear] = element;
            }
            else arr[++rear] = element;
            printf("Elements of queue: ");
            for(int b = front; b < rear+1; b++) printf("%d ", arr[b]);
            printf("\n");
        }
        else if(operation == 'd'){
            if(front == rear){
                if(rear == -1) printf("Queue Underflow\n");
                else{
                    front = rear = -1;
                    printf("Queue has been emptied\n");
                }
                continue;
            }
            else{
                front++;
                printf("Elements of queue: ");
                for(int b = front; b < rear+1; b++) printf("%d ", arr[b]);
                printf("\n");
            }
        }
        else if(operation == 'q') return 0;
    }
    return 0;
}
