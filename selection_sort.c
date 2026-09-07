#include <stdio.h>

void swap(int *x, int *y){
    int hold = *x;
    *x = *y;
    *y = hold;
}

int mini(int *arr, int start, int size){
    int index = start;
    for(int i = start; i < size; i++) if(arr[i] < arr[index]) index = i;
    return index;
}

int main(){
    int size = 10, array[size];
    printf("Enter elements to sort: ");
    for(int *addr = array; addr < array+size; addr++) scanf("%d", addr);

    for(int pass = 1; pass < size; pass++){
        int small = mini(array, pass-1, size);
        swap(&array[small], &array[pass-1]);
    }

    printf("Sorted elements: ");
    for(int *addr = array; addr < array+size; addr++) printf("%d ", *addr);
    printf("\n");

    return 0;
}
