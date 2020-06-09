#include <stdio.h>
#include <stdlib.h>

#define N 10


int intpart(int n, int m) {
    if((n == 1) || (m == 1)) return 1;
    if(n == m) return (1+intpart(n, m-1));
    int k;
    k = ((n-m) >= m)? m:(n-m);
    return (intpart(n, m-1)+intpart(n-m, k));
}


int main() {
    int k;
    k = intpart(N, N-1);

    printf("%d\n", k+1);


    return 0;
}