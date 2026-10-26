#include <stdio.h>

int main(){
    int N = 20, arr[N], n, size = 7;
    for(int i = 0; i < size; i++){
        arr[i] = i;
        printf("%d ", arr[i]);
    }
    printf("\nEnter index of value to delete: ");
    scanf("%d", &n);
    for(int i = n; i < size-1; i++) arr[i] = arr[i+1];
    size--;
    printf("New array: ");
    for(int k = 0; k < size; k++) printf("%d ", arr[k]);
    printf("\n");

    return 0;
}
