#include <stdio.h>

void swap(int *x, int *y){
    int hold = *x;
    *x = *y;
    *y = hold;
}

void quicksort(int *unsorted, int start, int end){
    if(start < end){
        int pivot = end;
        int pivotpos = start;
        for(int i = start; i < end; i++){
            if(unsorted[i] < unsorted[pivot]){
                swap(&unsorted[i], &unsorted[pivotpos]);
                pivotpos++;
            }
        }
        swap(&unsorted[pivot], &unsorted[pivotpos]);
        quicksort(unsorted, start, pivotpos-1);
        quicksort(unsorted, pivotpos+1, end);
    }
}

int main(){
    int capacity = 7, unsorted[capacity];
    printf("Enter %d elements to sort: ", capacity);
    for(int *p = unsorted; p < unsorted+capacity; p++) scanf("%d", p);
    quicksort(unsorted, 0, capacity-1);
    printf("Sorted elements: ");
    for(int *p = unsorted; p < unsorted+capacity; p++) printf("%d ", *p);
    printf("\n");

    return 0;
}
