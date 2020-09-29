#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void n_queen(int *arr[], int row, int column, int count, int n) {

    for(int i=column;i<n;i++) {
        if(arr[row][i] == 0) {
            arr[row][i] = 2;
            mark(arr, row, i);
            n_queen(arr, )
            revert_mark(arr, row, i);
        }
    }


}

int main() {

    int **arr;
    int n;

    scanf("%d", &n);
    
    arr = (int **)malloc(sizeof(int *)*n);
    arr[0] = (int *)malloc(sizeof(int)*n*n);

    for(int i=1;i<n;i++) {
        arr[i] = arr[i-1]+n;
    }

    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            arr[i][j] = 0;
        }
    }

    n_queen(arr, row, column, count, n);

// free memory

    free(arr[0]);
    free(arr);

    return 0;
}