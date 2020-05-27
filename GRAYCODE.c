#include <stdio.h>
#include <stdlib.h>

int N = 4;

void printb(int a) {
    int b[10] = {};
    int count = 0;
    while(a > 0) {
        b[count++] = (a&0x01UL);
        a>>=1;
    }
    int i;
    for(i=count-1;i>=0;i--) {
        printf("%d", b[i]);
    }
    printf("\n");
}

void power(int a[], int b[], int k) {
    int i;
    b[k] = 1;
    for(i = 0;i < N;i++) {
        if(b[i] == 1) printf("%d", a[i]);
    }
    printf("\n");
    if(k < N-1) power(a, b, k+1);
    b[k] = 0;
    if(k < N-1) power(a, b, k+1);
}



int main() {
    int tmp_N = 4;
    int a[1<<N];
    int b[1<<4]={};
    a[0] = 0; a[1] = 1; a[2] = 3; a[3] = 2;
    int i, j;
    long int tmp_value;
    long int tmp_index;
    for(i=2;i<N;i++){
        tmp_value = 1<<i;
        tmp_index = 1<<(i+1);
        for(j=1<<i;j<(1<<(i+1));j++) {
            a[j] = a[tmp_index-j-1]+tmp_value;
        }
    }

    power(a, b, 0);
    /*
    for(i=0;i<(1<<N);i++) {
        printb(a[i]);
    }
    printf("\n");
    */
    return 0;
}