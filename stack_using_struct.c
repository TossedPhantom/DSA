#include <stdio.h>

struct Stack {
    int arr[5];
    int *top;
};
void push(struct Stack *s, int value){
    if(s->top == 0){
        s->top = &s->arr[0];
        *s->top = value;
    }
    else if(s->top == &s->arr[4]) printf("Stack Overflow\n");
    else *++s->top = value;
}
void pop(struct Stack *s){
    if(s->top == 0) printf("Stack Underflow\n");
    else if(s->top == &s->arr[0]) s->top = 0;
    else s->top--;
}
void sprint(struct Stack *s){
    if(s->top == 0) printf("Stack is empty\n");
    else{
        for(int *p = &s->arr[0]; p < s->top+1; p++) printf("%d ", *p);
        printf("\n");
    }
}
int inp(int *target){
    printf("Enter element: ");
    scanf("%d", target);
    return *target;
}
char cinp(char *operation){
    printf("Enter operation: ");
    scanf(" %c", operation);
    return *operation;
}

int main(){
    struct Stack stack;
    char operation;
    int target;
    stack.top = 0;
    while(1){
        switch(cinp(&operation)){
            case 'p':
                push(&stack, inp(&target));
                sprint(&stack);
                break;
            case 'o':
                pop(&stack);
                sprint(&stack);
                break;
            case 'q':
                return 0;
        }
    }

    return 0;
}
