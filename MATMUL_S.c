#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX(x, y) ((x>=y)?x:y;)
#define MIN(x, y) ((x<=y?x:y;))

#define GAP(a, b) ((a<b)?gap:1;)

void StwoD_to_oneD(int TwoD[][MAXSIZE], int n, int OneD[]){
    int index;

    for(int i=0;i<n;i++) {
        for(int j=i;j<n;j++) {
            OneD[index++] = TwoD[i][j];
        }
    }
}
void oneD_to_StwoD(int OneD, int TwoD[][MAXSIZE], int n){
    int index;

    for(int i=0;i<n;i++) {
        for(int j=i;j<n;j++) {
            TwoD[i][j] = OneD[index];
            TwoD[j][i] = OneD[index++];
        }
    }
}
void Smatmul(int a[], int b[], int c[], int n) {

    int sum;
    int gap;

    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            sum = 0;
            gap = n-1;
            p = i;
            q = j;
            for(int k=0;k<n;k++,p+=GAP(k, i), q+=GAP(k, j), gap--) {
                sum += a[p]*b[q];
            }
            c[i*n+j] = sum;
        }
    }
}

