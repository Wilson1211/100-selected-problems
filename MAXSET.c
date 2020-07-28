#include <stdio.h>
#include <stdlib.h>
//#include <math.h>

#define   MAXSIZE   1000
#define   MIN(x, y) ((x<=y)?x:y)
//#define   SWAP(x, y) {int *t; t = x;x = y;y = t;}


void maxset(int x[][2], int n){
    int i;
    int *index = (int *)malloc(sizeof(int));

    for(i=0;i<n;i++){
        index[i] = 0;
        for(j=i+1;j<n;j++){
            if(x[j][0]>x[i][0] && (x[j][1]>x[i][1])) break;
        }
        if(j==n) index[i] = 1;
    }
}

