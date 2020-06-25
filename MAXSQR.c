#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10

#define min(a,b,c) ((a<b)?((a<c)?a:c):((b<c)?b:c))

typedef int MATRIX[MAXSIZE][MAXSIZE];


void maxsquare(MATRIX x, int n, int key, int*width, int* row, int* col ) {
    MATRIX y = {{}};
    int i, j, k;
    
    i = n-1;
    for(j=0;j<n;j++){
        if(x[i][j] == key) y[i][j] = 1;
        if(x[j][i] == key) y[j][i] = 1;
    }


    for(i=n-2;i>=0;i--){
        for(j=n-2;j>=0;j--){
            y[i][j] = (y[i][j] == key)?(1+min(y[i+1][j], y[i][j+1], y[i+1][j+1])):0;
        }
    }

    *width = 0;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(y[i][j] > *width){
                *row = j;
                *col = i;
                *width = y[i][j];
            }
        }
    }    
}