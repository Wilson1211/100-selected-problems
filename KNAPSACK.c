#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define N 10
#define MIN(a, b) ((a>b)?b:a)


void knapsack(int pack[], int n, int p, int K) {

    

}

int main() {

    int i, j, k, n, p, K;
    int *pack;
    scanf("%d", &n);
    scanf("%d", &p);
    scanf("%d", &K);
    pack = (int *)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++) {
        scanf("%d", pack[i]);
    }

    free(pack);
    return 0;
}