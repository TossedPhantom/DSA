#include <stdio.h>

void swap(int *x, int *y){
    int hold = *x;
    *x = *y;
    *y = hold;
}

int main(){
    int length = 8, arr[length];
    printf("Enter elements to sort: ");
    for(int *i = arr; i < arr+length; i++) scanf("%d", i);

    for(int a = 0; a < length-1; a++)
        for(int b = 0; b < length-1-a; b++) if(arr[b] > arr[b+1]) swap(&arr[b], &arr[b+1]);
    for(int c = 0; c < length; c++) printf("%d ", arr[c]);
    printf("\n");

    return 0;
}
