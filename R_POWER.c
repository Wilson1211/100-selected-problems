#include <stdio.h>
#include <stdlib.h>
#include "L_SIEVE.c"


int r_power(int n, int m){
    if(n == 1) return m;
    if(n % 2 == 0){
        return r_power(m, n/2)*r_power(m, n/2);
    }else{
        return r_power(m, n/2)*r_power(m, n-n/2);
    }
}