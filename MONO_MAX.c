#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mono_max(int arr[][5], int *res[], int start, int end, int m){
    if(end-start<=1) {
        return;
    }
    int mid = (end+start)/2;
    int max = 0;
    for(int i=res[start][0];i<=res[end][0];i++) {
        if(max < arr[mid][i]) {
            max = arr[mid][i];
            res[mid][0] = i;
            res[mid][1] = max;
        }
    }
    mono_max(arr, res, start, mid, m);
    mono_max(arr, res, mid, end, m);
}

int main() {
    int arr[5][5] = {{3, 2, 1, 1, 0}, 
                     {1, 3, 1, 2, 1},
                     {2, 3, 1, 0, 2},
                     {3, 3, 5, 4, 1},
                     {2, 3, 4, 5, 6}};

    int m = 5;
    int max;
    int **res;
    res = (int **)malloc(sizeof(int*)*m);
    res[0] = (int *)malloc(sizeof(int)*m*2);
    for(int i=1;i<m;i++) {
        res[i] = res[i-1]+2;
    }

    max = 0;
    for(int i=0;i<m;i++) {
        if(max < arr[0][i]){
            max = arr[0][i];
            res[0][1] = max;
            res[0][0] = i;
        }
    }
    for(int i=0;i<m;i++) {
        if(max < arr[m-1][i]){
            max = arr[m-1][i];
            res[m-1][1] = max;
            res[m-1][0] = i;
        }
    }
                 

    mono_max(arr, res, 0, m-1, m);

// print result
    for(int i=0;i<m;i++) {
        printf("i: %d, value: %d\n", res[i][0], res[i][1]);
    }


// free memory

    free(res[0]);
    free(res);

    return 0;
}