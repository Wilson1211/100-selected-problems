#include <stdio.h>
#include <stdlib.h>


int main() {

    int n, p, K;
    int *item;
    int ***dp;

    scanf("%d", &n);
    scanf("%d", &p);
    scanf("%d", &K);

    item = (int *)malloc(sizeof(int)*n);

    for(int i=0;i<n;i++) {
        scanf("%d", &item[i]);
    }

    dp = (int***)malloc(sizeof(int **)*(n+1));
    for(int i=0;i<=n;i++) {
        dp[i] = (int **)malloc(sizeof(int*)*(p+1));
        for(int j=0;j<=p;j++) {
            dp[i][j] = (int*)malloc(sizeof(int)*(K+1));
        }
    }




    for(int i=0;i<=n;i++) {
        for(int j=0;j<=p;j++) {
            free(dp[i][j]);
        }
        free(dp[i]);
    }
    
    free(dp);
    free(item);


    return 0;
}