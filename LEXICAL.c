#include <stdio.h>
#include <stdlib.h>


int N = 4;

void power(int a[], int b) {

    int i;
    a[b] = 1;
    for(i = 0;i < N;i++) {
        if(a[i] == 1) printf("%d", i+1);
    }
    printf("\n");
    if(b < N-1)  power(a, b+1);
    a[b] = 0;
        /*
        for(i = 0;i < N;i++) {
            if(a[i] == 1) printf("%d", i+1);
        }
        printf("\n");
        */
    if(b < N-1) power(a, b+1);
    
    return ;
}



int main() {
    int a[4] = {};
    power(a, 0);
    return 0;
}