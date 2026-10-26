#include <stdio.h>

int main(){
    int arr[5], arr2[5], *p, *q;
    printf("Enter arr1: ");
    for(p = arr; p < arr+5; p++) scanf("%d", p);
    printf("Enter arr2: ");
    for(q = arr2; q < arr2+5; q++) scanf("%d", q);
    printf("Multiplication: ");
    for(p = arr, q = arr2; p < arr+5; p++, q++) printf("%d ", *p * *q);
    printf("\n");

    return 0;
}
