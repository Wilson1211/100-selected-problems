#include <stdio.h>
#include <stdlib.h>
#include "L_SIEVE.c"

int fib_it(const int n){
    int i;
    int a = 1, ans = 2;
    for(i = 3; i < n; i++){
        a = ans - a;
        ans += a;
    }
    
    return ans;

}