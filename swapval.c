#include <stdio.h>

void swap(int *x, int *y){
    int hold = *x;
    *x = *y;
    *y = hold;
}

int main(){
    int x, y;
    printf("X: ");
    scanf("%d", &x);
    printf("Y: ");
    scanf("%d", &y);
    swap(&x, &y);
    printf("After swap:\nX: %d\nY: %d\n", x, y);


    return 0;
}
