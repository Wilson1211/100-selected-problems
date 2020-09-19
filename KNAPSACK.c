#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX3(x, y, z) ((x>=y)?((x>=z)?x:z):((y>=z)?y:z))
#define MAX2(x, y) ((x>=y)?x:y)
#define debug

int main() {

    int n, P, K;
    int *item;
    int ***dp;

    scanf("%d", &n);
    scanf("%d", &P);
    scanf("%d", &K);

    item = (int *)malloc(sizeof(int)*n);

    for(int i=0;i<n;i++) {
        scanf("%d", &item[i]);
    }

    dp = (int***)malloc(sizeof(int **)*(K+1));
    for(int i=0;i<=K;i++) {
        dp[i] = (int **)malloc(sizeof(int*)*(n+1));
        for(int j=0;j<=n;j++) {
            dp[i][j] = (int*)malloc(sizeof(int)*(P+1));
            memset(dp[i][j], 0, P+1);
        }
    }
    for(int j=0;j<=K;j++) {
        for(int p=1;p<=P;p++) {
            for(int i=0;i<n;i++) {
                for(int m=0;m<=i;m++) {
                    if(item[i] <= j) {    
                        if(dp[j-item[i]][m][p-1]+item[i] <= j) {
                            dp[j][i+1][p] = MAX2(MAX3(dp[j][m][p], dp[j-item[i]][m][p-1]+item[i], item[i]), dp[j][i+1][p]);
                        }
                        dp[j][i+1][p] = MAX3(dp[j][m][p], item[i], dp[j][i+1][p]);
                    }
                }
            }
        }
    }

#ifdef debug
    for(int j=0;j<=K;j++) {
        printf("j: %d\n", j);
        for(int i=0;i<=n;i++) {
            for(int p=1;p<=P;p++) {
                printf("%2d",dp[j][i][p]);
            }
            printf("\n");
        }
    }
#endif



    if(dp[K][n][P] == K) {
        printf("found\n");
    }else{
        printf("not found\n");
    }



// free memory allocation
    for(int i=0;i<=K;i++) {
        for(int j=0;j<=n;j++) {
            free(dp[i][j]);
        }
        free(dp[i]);
    }
    
    free(dp);
    free(item);


    return 0;
}