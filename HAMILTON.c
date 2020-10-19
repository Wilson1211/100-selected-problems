#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void hamilton(int *arr[], int *record, int city, int count, int n) {
    if(count == n) {
        if(arr[city][1]) {
            record[city] = 1;
            printf("yes\n");
            for(int i=1;i<=n;i++) {
                printf("%d ", record[i]);
            }
            record[city] = 0;
            printf("\n");
            return;
        }
    }
    for(int i=1;i<=n;i++) {
        if(arr[city][i] && (!record[i])) {
            record[city] = i;
            hamilton(arr, record, i, count+1, n);
            record[city] = 0;
        }
    }
}


int main() {

    int **arr;
    int *record;
    int n;
    int row, column;

    scanf("%d", &n);

    arr = (int **)malloc(sizeof(int*)*(n+1));
    arr[0] = (int *)malloc(sizeof(int)*(n+1)*(n+1));
    for(int i=1;i<=n;i++) {
        arr[i] = arr[i-1]+n;
    }

    for(int i=0;i<=n;i++) {
        for(int j=0;j<=n;j++) {
            arr[i][j] = 0;
        }
    }

    do{
        scanf("%d %d", &row, &column);
        arr[row][column] = 1;
        arr[column][row] = 1;
    }while(row || column);

    record = (int *)malloc(sizeof(int)*(n+1));
    for(int i=0;i<=n;i++) {
        record[i] = 0;
    }
    hamilton(arr, record, 1, 1, n);   


// free memory
    free(record);
    free(arr[0]);
    free(arr);

    return 0;
}