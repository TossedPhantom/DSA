#include <stdio.h>

void insertionsort(int *unsorted, int capacity){
 for(int i = 1; i < capacity; i++){
     int j = i-1;
     int tmp = unsorted[i];
     while(j >= 0 && unsorted[j] > tmp){
         unsorted[j+1] = unsorted[j];
         j--;
     }
     unsorted[j+1] = tmp;
 }
}

int main(){
    int capacity = 7, unsorted[capacity];
    printf("Enter %d elements to sort: ", capacity);
    for(int *p = unsorted; p < unsorted+capacity; p++) scanf("%d", p);
    insertionsort(unsorted, capacity);
    printf("Sorted array: ");
    for(int *p = unsorted; p < unsorted+capacity; p++) printf("%d ", *p);
    printf("\n");

    return 0;
}
