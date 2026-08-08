#include <stdio.h>

int main(){
    int N = 20, arr[N];
    for(int i = 0; i < 7; i++){
        arr[i] = i;
        printf("%d ", arr[i]);
    }
    printf("\nEnter index and value: ");
    int n, d;
    scanf("%d %d", &n, &d);
    for(int k = 8; k > n; k--) arr[k] = arr[k-1];
    arr[n] = d;
    printf("New Array: ");
    for(int l = 0; l < 8; l++) printf("%d ", arr[l]);
    printf("\n");

    return 0;
}
