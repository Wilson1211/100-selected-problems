#include <stdio.h>
#include <stdlib.h>



void sieve(const int N){
    int i = 2, M;
    int *a = malloc(N);
    memset(a, 0, N);
    int ptr1 = 3, ptr2;

    while(i + i < N) i++;
    M = i - 1;
    while(ptr1 <= M) {
        ptr2 = ptr1;
        while(ptr2 < N){
            a[ptr2] = 1;
            ptr2 += (ptr1 + ptr1);
        }
        ptr1 += 2;
        while(a[ptr1] == 1) ptr1 += 2; 
    }
}