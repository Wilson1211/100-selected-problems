#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define N 10
#define MIN(a, b) ((a>b)?b:a)

int main() {

    int N, K, L, M;
    int *input;
    int **arr, **f;

    scanf("%d", &N);
    input = (int *)malloc(sizeof(int)*N);
    for(int i=0;i<N;i++) {
        scanf("%d", &input[i]);
    }    


    arr = (int **)malloc(sizeof(int *)*N);
    f = (int **)malloc(sizeof(int *)*N);
    
    for(int i=0;i<N;i++) {
        arr[i] = (int*)malloc(sizeof(int)*N);
        f[i] = (int*)malloc(sizeof(int)*N);
        memset(arr[i], 0, N);
        memset(f[i], 0, N);
    }

    for(int j=0;j<N;j++) {
        for(int i=0)
        arr[i][i+1] = ;
    }



}