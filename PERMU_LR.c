#include <stdio.h>
#include <stdlib.h>

#define N  4

void printall(int a[]) {
    int i, j;
    for(i = 1;i <= N; i++) {
        j = 0;
        while(a[j] != i) j++;
        if(a[j] == i) printf("%d", j+1);
    }
    printf("\n");
}


void demon_all_permute(int a[], int k) {
    if(k == 0) {
        printall(a);
        return;
    }
    int i = 0, j;
    for(i=0;i<N;i++){
        if(a[i] == 0) {
            a[i] = N-k+1;
            //printf("i = %d, k = %d\n", i, k); 
            demon_all_permute(a, k-1);
            a[i] = 0;
        }
    }    
}


int main() {
    int a[N] = {};
    int i;
 //   for(i = 0;i < N; i++) {
 //       a[i] = 1;
    demon_all_permute(a, N);
 //   }


}