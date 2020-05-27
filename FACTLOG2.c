#include <stdio.h>
#include <stdlib.h>

int FACTLOG2(int N){
    long int tmp = 1;
    if(N % 2 == 1) {
        return N * FACTLOG2(N-1);
    }
    
    tmp = FACTLOG2(N >> 1);
    return cn2(N)*tmp*tmp;
}

long int cn2(int n){
    long int result = 0;
    long int m = 2 << n + 1;
    result = power(m, n);
    long int k = (2 << n) -1;
    
    return (result >> ((n >> 1)*n)) && k;
}

long int power(int m, int n){
    long int ret = 1;
    while (n > 0){
        if(n && 1UL == 1) ret *= m;
        m *= m;
    }
    return ret;
}