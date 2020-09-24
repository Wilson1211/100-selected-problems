#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>


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
        memset(arr[i], INT_MAX, N);
        memset(f[i], 0, N);
    }
    for(i=0;i<N;i++) {
        arr[i][i] = 0;
    }

    for(int j=1;j<N;j++) {
        for(int i=j-1;i>=0;i--) {
            for(int k=i;k<j;k++) {
                if(arr[i][k]+arr[k+1][j]+input[2*i]*input[2*k+1]*input[2*j+1] < arr[i][j]) {
                    arr[i][j] = arr[i][k]+arr[k+1][j]+input[2*i]*input[2*k+1]*input[2*j+1];
                    f[i][j] = k;
                }
            }
        }
    }

    for(int i=0;i<N;i++) {
        free(arr[i]);
        free(f[i]);
    }
    free(arr);
    free(f);

}