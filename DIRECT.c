#include <stdio.h>
#include <stdlib.h>

#define N 3

void direct(int a[], int k) {
    if(k == N) return;
    a[k] = 1;
    int i;
    for(i=0;i<N;i++) {
        if(a[i]) printf("%d", i+1);
    }
    printf("\n");
    direct(a, k+1);
    a[k] = 0;
    direct(a, k+1);
}



int main() {

    int i;
    int a[N] = {};
    
    direct(a, 0);
    

    return 0;
}

