#include <stdio.h>

struct Stack{
    char arr[100];
    char *top;
    int occupied;
};

void push(struct Stack *s, char value){
    if(s->occupied == 100) printf("Stack Overflow\n");
    else if(s->top == 0){
        s->top = &s->arr[0];
        *s->top = value;
        s->occupied++;
    }
    else{
        *++s->top = value;
        s->occupied++;
    }
}

void pop(struct Stack *s){
    if(s->occupied == 0) printf("Stack Underflow\n");
    else if(s->top == &s->arr[0]){
        s->top = 0;
        s->occupied--;
    }
    else{
        s->top--;
        s->occupied--;
    }
}

void expscan(char *exp){
    printf("Enter expression: ");
    fgets(exp, 100, stdin);
}

int main(){
    char expression[100];
    expscan(expression);
    struct Stack operator;
    operator.top = 0;
    operator.occupied = 0;
    char output[100];
    int length = 0;
    for(int i = 0; i < 100; i++){
        if(expression[i] == ' ') continue;
        if(expression[i] == '(') push(&operator, expression[i]);
        else if(expression[i] == '+'){
            while(operator.occupied != 0 && (*operator.top == '*' || *operator.top == '/')){
                output[length++] = *operator.top;
                output[length] = '\0';
                pop(&operator);
            }
            if(operator.occupied != 0 && *operator.top == '-'){
                output[length++] = *operator.top;
                output[length] = '\0';
                pop(&operator);
                push(&operator, expression[i]);
            }
            else push(&operator, expression[i]);
        }
        else if(expression[i] == '-'){
            while(operator.occupied != 0 && (*operator.top == '*' || *operator.top == '/')){
                output[length++] = *operator.top;
                output[length] = '\0';
                pop(&operator);
            }
            if(operator.occupied != 0 && *operator.top == '+'){
                output[length++] = *operator.top;
                output[length] = '\0';
                pop(&operator);
                push(&operator, expression[i]);
            }
            else push(&operator, expression[i]);
        }
        else if(expression[i] == '/'){
            if(operator.occupied != 0 && *operator.top == '*'){
                output[length++] = *operator.top;
                output[length] = '\0';
                pop(&operator);
                push(&operator, expression[i]);
            }
            else push(&operator, expression[i]);
        }
        else if(expression[i] == '*'){
            if(operator.occupied != 0 && *operator.top == '/'){
                output[length++] = *operator.top;
                output[length] = '\0';
                pop(&operator);
                push(&operator, expression[i]);
            }
            else push(&operator, expression[i]);
        }
        else if(expression[i] == ')'){
            while(*operator.top != '('){
                output[length++] = *operator.top;
                output[length] = '\0';
                pop(&operator);
            }
            pop(&operator);
        }
        else if(expression[i] >= 'A' && expression[i] <= 'Z'){
            output[length++] = expression[i];
            output[length] = '\0';
        }
        else if(expression[i] == '\0'){
            while(operator.occupied != 0){
                output[length++] = *operator.top;
                output[length] = '\0';
                pop(&operator);
            }
            break;
        }
    }
    printf("Postfix Expression: %s\n", output);

    return 0;
}
