#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n, t, row, column;
    int **arr;
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

    t = n*n;
    row = 0; column = n/2;
    for(int i=0;i<t;i++) {
        if(arr[row][column]!=0) {
            row = (n+row+2)%n;
            column = (n+column-1)%n;
        }
        arr[row][column] = i+1;
        row = (n+row-1)%n;
        column = (n+column+1)%n;
    }

    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            printf("%2d ", arr[i][j]);
        }
        printf("\n");
    }
// free memory
    free(arr[0]);
    free(arr);

    return 0;
}