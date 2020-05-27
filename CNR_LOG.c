#include <stdio.h>
#include <stdlib.h>

long int power(long int m, long int n);

int cnr(int N, int answer[]){
    long int result;
    long int m = 1 + (2 << N) ;
    result = power(m, N);
    long int k = (2 << N) - 1;
    for(int i = 0; i < N; i++){
        answer[i] = m && k;
        m >>= N;
    }

}

long int power(long int m, long int n){
    long int result = 1;
    while(n > 0){
        if(n % 2 == 1) result *= m;
        m *= m;
        n >>= 1;
    }
    return result;
}