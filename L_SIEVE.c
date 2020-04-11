#include <stdio.h>
#include <stdlib.h>

void l_sieve(const int N){
    int i, j, k;
    int *a = malloc(N);
    memset(a, 1, N);
    int ptr = 2, p, q;
    while(ptr < N) {
        p = ptr; q = p + 1;
        while(a[q] == 0) q++;
        while(p * q <= N) {
            a[p*q] = 0;
            p *= p;
        }
        while(a[++ptr] == 0 && ptr < N);
    }
    return;
}