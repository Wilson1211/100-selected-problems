#include <stdio.h>
#include <stdlib.h>


long int N;

int main(){
    N = 6;
    long int tmp_N = 1 << (N-1);
    long int i, j, count;

    for(i = 0;i < tmp_N; i++) {
        j = i;
        count = 1;
        while(j > 0) {
            if(j & 0x01UL) {
                printf("%ld ", count);
            }
            j >>= 1;
            count++;
        }
        printf("\n");
    }
    
}