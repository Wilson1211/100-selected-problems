#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX(x, y) ((x>=y)?x:y;)
#define MIN(x, y) ((x<=y)?x:y;)
#define MAXSIZE    10


void twoD_to_oneD(int TwoD[][MAXSIZE], int m, int n, int OneD[]);
void oneD_to_twoD(int OneD[], int TwoD[][MAXSIZE], int m, int n);
void matmul(int a[], int b[], int c[], int L, int M, int N);

void twoD_to_oneD(int TwoD[][MAXSIZE], int m, int n, int OneD[]){
    int index;

    index = 0;
    for(int i=0;i<m;i++) {
        for(int j=0;j<n;j++) {
            oneD[index++] = TwoD[i][j];
        }
    }
}

void oneD_to_twoD(int OneD[], int TwoD[][MAXSIZE], int m, int n){
    int index;

    index = 0;
    for(int i=0;i<m;i++) {
        for(int j=0;j<n;j++) {
            TwoD[i][j] = OneD[index++];
        }
    }
}


void matmul(int a[], int b[], int c[], int L, int M, int N) {
    int i, j, k;

    for(int i=0;i<L;i++) {
        for(int j=0;j<N;j++) {
            for(int k=0;k<M;k++) {
                c[i*M+j] += a[i*M+k]*b[j+k*M];
            }
        }
    }
}