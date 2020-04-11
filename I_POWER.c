#include <stdio.h>
#include <stdlib.h>
#include "L_SIEVE.c"


int r_power(int n, int m){
    int p, q = m;
    while(n != 1) {
        p = n >> 1;
        m *= m;
        if(p == 1) m *= q;
    }
    return m;
}

