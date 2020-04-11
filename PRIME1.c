#include <stdio.h>
#include <stdlib.h>
//#include <vector>

#define N 10000


bool prim_check(int num, int ptr[], const int n){
    for(int i = 0; ptr[i]*ptr[i] <= num, i < n; i++){
        if(num  % ptr[i] != 0) return 0;
    }
    return 1;
}


void prime(){
    int i, j=3, k;
    int prim[N];
    prim[0] = 2;prim[1] = 3;prim[3] = 5;
    i = 1;
    while(6*i < N) {
        if(prim_check(6*i+1, prim, j)) prim[j++] = 6*i+1;
        if(prim_check(6*i+5, prim, j)) prim[j++] = 6*i+5;
        i++;
    }

}