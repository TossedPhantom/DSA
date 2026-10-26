#include <stdio.h>

void inp(int *rear){
    printf("Enter element: ");
    scanf("%d", rear);
}
void qprint(int *front, int *rear){
    for(int *p = front; p < rear+1; p++) printf("%d ", *p);
    printf("\n");
}

int main(){
    int arr[5], *front = 0, *rear = 0;
    char operation;
    while(1){
        printf("Enter operation: ");
        scanf(" %c", &operation);
        switch(operation){
            case 'e':
                if(rear == &arr[4]){
                    printf("Queue Overflow\n");
                    continue;
                }
                if(front == 0){
                    front = &arr[0];
                    rear = front;
                    inp(rear);
                    qprint(front, rear);
                }
                else{
                    inp(++rear);
                    qprint(front, rear);
                }
                break;
            case 'd':
                if(front == 0) printf("Queue underflow\n");
                else if(front == &arr[4]){
                    front = 0;
                    rear = 0;
                    printf("Queue has been emptied\n");
                }
                else{
                    front++;
                    qprint(front, rear);
                }
                break;
            case 'q':
                return 0;
        }
    }

    return 0;
}
