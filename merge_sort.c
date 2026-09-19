#include <stdio.h>

void merge(int *unsorted, int start, int end){
    int middle = (start+end)/2;
    int tmp[end+1];
    for(int a = start, b = middle+1, c = start; c <= end; c++){
        if(a <= middle && b <= end){
            if(unsorted[a] <= unsorted[b]){
                tmp[c] = unsorted[a];
                a++;
            }
            else if(unsorted[b] < unsorted[a]){
                tmp[c] = unsorted[b];
                b++;
            }
        }
        else if(a > middle){
            tmp[c] = unsorted[b];
            b++;
        }
        else if(b > end){
            tmp[c] = unsorted[a];
            a++;
        }
    }
    for(int a = start; a <= end; a++) unsorted[a] = tmp[a];
}

void merge_sort(int *unsorted, int start, int end){
    int middle = (start+end)/2;
    if(start<end){
        merge_sort(unsorted, start, middle);
        merge_sort(unsorted, middle+1, end);
    }
    merge(unsorted, start, end);
}

int main(){
    int capacity = 7, unsorted[capacity];
    printf("Enter %d elements to sort: ", capacity);
    for(int *p = unsorted; p < unsorted+capacity; p++) scanf("%d", p);
    merge_sort(unsorted, 0, capacity-1);
    printf("Sorted Array: ");
    for(int *p = unsorted; p < unsorted+capacity; p++) printf("%d ", *p);
    printf("\n");

    return 0;
}
