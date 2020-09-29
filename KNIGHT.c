#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void knight(int *arr[], int n) {
    
}

int main() {
    int **arr;
    int n;
    scanf("%d", &n);

    arr = (int **)malloc(sizeof(int*)*n);
    arr[0] = (int *)malloc(sizeof(int)*n*n);

    for(int i=1;i<n;i++) {
        arr[i] = arr[i-1]+n;
    }

    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            arr[i][j] = 0;
        }
    }

    knight(arr, n);

// free memory
    free(arr[0]);
    free(arr);

    return 0;
}