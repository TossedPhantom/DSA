#include <stdio.h>

void qprint(int arr[], int arr_size, int front, int rear){
    if(front > rear){
        for(int b = 0; b < rear+1; b++) printf("%d ", arr[b]);
        for(int a = front; a < arr_size; a++){
            if(a == front) printf("[%d ", arr[a]);
            else printf("%d ", arr[a]);
        }
        printf("\n");
    }
    else{
        for(int c = front; c < rear+1; c++) printf("%d ", arr[c]);
        printf("\n");
    }
}

int main(){
    int arr_size = 7, arr[arr_size], front = -1, rear = -1, element, occupied = 0;
    char operation;
    while(1){
        printf("Enter operation: ");
        scanf(" %c", &operation);
        switch(operation){
            case 'e':
                if(occupied == arr_size){
                    printf("Queue Overflow\n");
                    continue;
                }
                printf("Enter element: ");
                scanf("%d", &element);
                if(front == -1){
                    front++;
                    arr[++rear] = element;
                    occupied++;
                    qprint(arr, arr_size, front, rear);
                }
                else if(rear == arr_size - 1){
                    rear = 0;
                    arr[rear] = element;
                    occupied++;
                    qprint(arr, arr_size, front, rear);
                }
                else{
                    arr[++rear] = element;
                    occupied++;
                    qprint(arr, arr_size, front, rear);
                }
                break;
            case 'd':
                if(front == rear){
                    if(rear == -1) printf("Queue underflow\n");
                    else{
                        front = rear = -1;
                        occupied--;
                        printf("Queue has been emptied\n");
                    }
                }
                else if(front == arr_size - 1){
                    front = 0;
                    occupied--;
                    qprint(arr, arr_size, front, rear);
                }
                else{
                    front++;
                    occupied--;
                    qprint(arr, arr_size, front, rear);
                }
                break;
            case 'q':
                return 0;
        }
    }

    return 0;
}
