#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define   MAXSIZE   1000

/*
    for(int j=0;j<n;j++) {
        for(int i=0;i<n;i++) {
            target = M[i][j];
            printf("i: %d, j: %d, target: %d\n", i, j, target);
            for(int k=0;k<result_W[target];k++) {
                if(W[target][k] == i) {
                    result_W[target] = k;
                    printf("target: %d, k: %d\n", target, k);
                    break;
                }
            }
        }
        printf("=================\n");
        for(int i=0;i<n;i++) {
            printf("%d %d\n", i, W[i][result_W[i]]);
        }
    }

    printf("=================\n");
    for(int i=0;i<n;i++) {
        printf("%d\n", W[i][result_W[i]]);
    }

    */





int main() {

    int n;
    int **M, **W;
    int **W_rev;
    int *result_W;
    int *result_M;
    int *next;
    int flag = 0;

    scanf("%d", &n);
    M = (int **)malloc(sizeof(int)*n);
    W = (int **)malloc(sizeof(int)*n);
    W_rev = (int **)malloc(sizeof(int)*n);
    M[0] = (int *)malloc(sizeof(int)*n*n);
    W[0] = (int *)malloc(sizeof(int)*n*n);
    W_rev[0] = (int *)malloc(sizeof(int)*n*n);


    for(int i=1;i<n;i++) {
        M[i] = M[i-1]+n;
        W[i] = W[i-1]+n;
        W_rev[i] = W_rev[i-1]+n;
    }


    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            scanf("%d", &M[i][j]);
        }
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            scanf("%d", &W[i][j]);
            W_rev[i][W[i][j]] = j;
        }
    }

    result_W = (int *)malloc(sizeof(int)*n);
    result_M = (int *)malloc(sizeof(int)*n);
    next = (int *)malloc(sizeof(int)*n);

    for(int i=0;i<n;i++) {
        next[i] = 0;
        result_W[i] = n;
        result_M[i] = n;
    }
    
// start process
    int target_pos, target;
    while(flag == 0) {
        flag = 1;
        for(int i=0;i<n;i++) {
            while(result_M[i] == n) {
                flag = 0;
                target_pos = next[i];
                target = M[i][target_pos];
                if(result_W[target] == n) {
                    result_M[i] = target;
                    result_W[target] = i;
                }
                else if(W_rev[target][result_W[target]] > W_rev[target][i]) {
                    next[result_W[target]]++;
                    result_M[result_W[target]] = n;
                    result_M[i] = target;
                    result_W[target] = i;
                }else{
                    next[i]++;
                }
            }
        }
    }
    
    for(int i=0;i<n;i++) {
        printf("%d : %d\n", i, result_M[i]);
    }

    for(int i=0;i<n;i++) {
        printf("%d : %d\n", i, result_W[i]);
    }

// free memory
    free(next);
    free(result_M);
    free(result_W);
    free(M[0]);
    free(W[0]);
    free(W_rev[0]);
    free(W_rev);
    free(M);
    free(W);
    return 0;
}