#include <stdio.h>

int main(){
    int N = 10, arr[N];
    printf("Enter 10 elements: ");
    for(int i = 0; i < N; i++) scanf("%d", &arr[i]);
    printf("Elements of array are: ");
    for(int j = 0; j < N; j++) printf("%d ", arr[j]);
    printf("\n");

    return 0;
}
