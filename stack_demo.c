#include <stdio.h>
#include <string.h>
int main(){
    int N = 7, arr[N], top = -1, number;
    printf("We have a stack with max capacity of 7 elements\n");
    char operation[5];
    while(1){
        printf("Enter operation to perform: ");
        scanf("%4s", operation);
        if(strcmp(operation, "push") == 0 || strcmp(operation, "p") == 0){
            if(top == N-1){
                printf("Stack Overflow\n");
                continue;
            }
            printf("Enter number: ");
            scanf("%d", &number);
            arr[++top] = number;
            printf("Stack: ");
            for(int i = 0; i <= top; i++) printf("%d ", arr[i]);
            printf("\n");
        }
        else if(strcmp(operation, "pop") == 0 || strcmp(operation, "o") == 0){
            if(top == -1){
                printf("Stack Underflow\n");
                continue;
            }
            top--;
            printf("Stack: ");
            for(int i = 0; i <= top; i++) printf("%d ", arr[i]);
            printf("\n");
        }
        else if(strcmp(operation, "quit") == 0 || strcmp(operation, "q") == 0) return 0;
        else printf("Invalid input\n");
    }

    return 0;
}
