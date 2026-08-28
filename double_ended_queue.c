#include <stdio.h>
#include <string.h>

struct queue{
    int arr[7];
    int *front;
    int *rear;
    int occupied;
};

void renqueue(struct queue *s, int value){
    if(s->occupied == 7) printf("Queue Overflow\n");
    else if(s->rear == &s->arr[6]){
        s->rear = &s->arr[0];
        *s->rear = value;
        s->occupied++;
    }
    else if(s->rear == 0){
        s->front = &s->arr[0];
        s->rear = &s->arr[0];
        *s->rear = value;
        s->occupied++;
    }
    else{
        *++s->rear = value;
        s->occupied++;
    }
}

void fdequeue(struct queue *s){
    if(s->occupied == 0) printf("Queue Underflow\n");
    else if(s->front == s->rear){
        s->front = 0;
        s->rear = 0;
        s->occupied--;
    }
    else if(s->front == &s->arr[6]){
        s->front = &s->arr[0];
        s->occupied--;
    }
    else{
        s->front++;
        s->occupied--;
    }
}

void fenqueue(struct queue *s, int value){
    if(s->occupied == 7) printf("Queue Overflow\n");
    else if(s->front == &s->arr[0]){
        s->front = &s->arr[6];
        *s->front = value;
        s->occupied++;
    }
    else if(s->front == 0){
        s->front = &s->arr[0];
        s->rear = &s->arr[0];
        *s->front = value;
        s->occupied++;
    }
    else{
        *--s->front = value;
        s->occupied++;
    }
}

void rdequeue(struct queue *s){
    if(s->occupied == 0) printf("Queue Underflow\n");
    else if(s->rear == s->front){
        s->front = 0;
        s->rear = 0;
        s->occupied--;
    }
    else if(s->rear == &s->arr[0]){
        s->rear = &s->arr[6];
        s->occupied--;
    }
    else{
        s->rear--;
        s->occupied--;
    }
}

void qprint(struct queue *s){
    if(s->front > s->rear){
        for(int *p = &s->arr[0]; p <= s->rear; p++) printf("%d ", *p);
        for(int *l = s->front; l <= &s->arr[6]; l++){
            if(l == s->front){
                printf("[%d ", *s->front);
                continue;
            }
            printf("%d ", *l);
        }
        printf("\n");
    }
    else if(s->occupied == 0) printf("Queue is empty\n");
    else{
        for(int *p = s->front; p <= s->rear; p++) printf("%d ", *p);
        printf("\n");
    }
}

void opscan(char *operation){
    printf("Enter operation: ");
    scanf("%3s", operation);
}

void vscan(int *target){
    printf("Enter value: ");
    scanf("%d", target);
}

int main(){
    struct queue s;
    s.front = 0;
    s.rear = 0;
    s.occupied = 0;
    char operation[4];
    int value;

    while(1){
        opscan(operation);
        if(strcmp(operation, "re") == 0){
            vscan(&value);
            renqueue(&s, value);
            qprint(&s);
        }
        else if(strcmp(operation, "fd") == 0){
            fdequeue(&s);
            qprint(&s);
        }
        else if(strcmp(operation, "fe") == 0){
            vscan(&value);
            fenqueue(&s, value);
            qprint(&s);
        }
        else if(strcmp(operation, "rd") == 0){
            rdequeue(&s);
            qprint(&s);
        }
        else if(strcmp(operation, "q") == 0) return 0;
    }

    return 0;
}
