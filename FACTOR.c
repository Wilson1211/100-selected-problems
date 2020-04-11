#include <stdio.h>
#include <stdlib.h>

void l_sieve(int *a, const int N){
    int i, j, k;
    int ptr = 2, p, q;
    while(ptr < N) {
        p = ptr; q = p + 1;
        while(a[q] == 0) q++;
        while(p * q <= N) {
            a[p*q] = 0;
            p *= p;
        }
        while(a[++ptr] == 0);
    }
    return;
}

void sub_factor(int num, int *a, int b[], int k){
    if(num == 1) return;
    int i = 2, ptr, count = 1;
    while(num % a[i] != 0 && i < sizeof(a)/sizeof(a[0]) && i <= num) i++;
    ptr = i;
    if(num % a[i] != 0) return;
    while(num % a[i*ptr] == 0) {
        i *= ptr;
        count++;
    }
    b[k][0] = ptr; b[k][1] = count;
    sub_factor(num/i, a, b, k+1);
    
    return ;
}

void factor(int *a, const int N){
    l_sieve(a, N);
    int b[N][2];
    sub_factor(N, a, b, 0);

}