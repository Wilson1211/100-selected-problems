#include <stdio.h>
#include <stdlib.h>

#define N 5
#define limit 3
int count = 0;

void direct(int a[], int k) {
    if(k == N) return;
    if(count == limit) return;
    int i;
    a[k] = 1;
    count++;
    if(count == limit) {
        for(i=0;i<N;i++) {
            if(a[i]) printf("%d", i+1);
        }
        printf("\n");
    }
    direct(a, k+1);
    a[k] = 0;
    count--;
    direct(a, k+1);
}



int main() {

    int i;
    int a[N] = {};
    direct(a, 0);
    

    return 0;
}

