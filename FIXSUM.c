#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Nx 4
#define Ny 10
#define N 5

int main() {
    int x[Nx] = {3,7,2,4};
    int y[Ny] = {1,5,2,3,2};
    int i, tmp, j;
    int d = 9;
    int rev_y[Ny];
    int same_y[Ny];
    memset(rev_y, -1, Ny*sizeof(int));
    memset(same_y, -1, Ny*sizeof(int));
#if 0
    for(i=0;i<Ny;i++){
        printf("rev[%d]=%d\n", i, rev_y[i]);
    }
    for(i=0;i<Ny;i++){
        printf("same_y[%d]=%d\n", i, same_y[i]);
    }
#else
    for(i=0;i<N;i++){
        tmp = y[i];
        if(rev_y[tmp] == -1) {
            rev_y[tmp] = i;
        } 
        else {
            j = rev_y[tmp];
            while(same_y[j]!= -1) j = same_y[j];
            same_y[j] = i;
        }
    }
#endif
#if 0
    for(i=0;i<Ny;i++){
        printf("rev[%d]=%d\n", i, rev_y[i]);
    }
    for(i=0;i<Ny;i++){
        printf("same_y[%d]=%d\n", i, same_y[i]);
    }
#else
    for(i=0;i<Nx;i++) {
        tmp = d-x[i];
        if(rev_y[tmp] != -1) {
            j = rev_y[tmp];
            printf("x[%d]+y[%d]\n", i, j);
            while(same_y[j] != -1) {
                j = same_y[j];
                printf("x[%d]+y[%d]\n", i, j);
            }
        }
    }
#endif
    return 0;
}