#include <stdio.h>

int bsearch(int arr[], int start, int end, int target){
    if(start > end) return -1;
    int middle = (start+end)/2;
    if(target == arr[middle]) return middle;
    else if(target < arr[middle]) return bsearch(arr, start, middle-1, target);
    else return bsearch(arr, middle+1, end, target);
}

int main(){
    int N = 20, arr[N], target;
    for(int i = 0; i < N; i++) arr[i] = i;
    printf("Enter number to search: ");
    scanf("%d", &target);
    int start = 0;
    int end = N-1;

    int result = bsearch(arr, start, end, target);
    if(result == -1) printf("%d not found in array containing %d-%d.\n", target, arr[start], arr[end]);
    else printf("%d found at %d.\n", target, result);

    return 0;
}
