#include <stdio.h>

int main(){
    int arr[7], arr2[7], *p, *q;
    printf("Enter arr1: ");
    for(p = arr; p < arr+7; p++) scanf("%d", p);
    printf("Enter arr2: ");
    for(q = arr2; q < arr2+7; q++) scanf("%d", q);
    printf("Sum: ");
    for(p = arr, q = arr2; p < arr + 7; p++, q++) printf("%d ", *p + *q);
    printf("\n");

    return 0;
}
