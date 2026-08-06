#include <stdio.h>

int bsearch(int arr[], int start, int end, int target){
    int middle = (start+end)/2;
    if(target == middle) return middle;
    else if(target < middle) return bsearch(arr, start, middle, target);
    else return bsearch(arr, middle, end, target);
}

int main(){
    int N = 20, arr[N], target;
    for(int i = 0; i < N; i++) arr[i] = i;
    printf("Enter number to search: ");
    scanf("%d", &target);
    int start = 0;
    int end = N;
    if(target < start || target > end){
        printf("%d not found in array containing 0-19.\n", target);
        return 0;
    }

    int result = bsearch(arr, start, end, target);
    printf("%d found at %d.\n", target, result);

    return 0;
}
