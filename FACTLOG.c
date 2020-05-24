#include <stdio.h>
#include <stdlib.h>

unsigned long cnr[100] = {};
unsigned long num = 0;
unsigned long p_size;



 unsigned long power(unsigned long n, unsigned long x) {
     unsigned long tmp;
     if(n == 1) return x;
     else {
         if(n & 0x01UL) {
             tmp = power(n - 1, x);
             return x * tmp;
         }else {
             tmp = power(n >> 1, x);
             tmp *= tmp;
             cnr[num++] = (tmp >> ((n>>1)*p_size)) & (x-2);
             return tmp;
         }
     }
 }

int main() {
    unsigned long i;
    unsigned long re;
    p_size = 11;
    unsigned long x = (1<<p_size)+1;
    re = power(p_size,x);
    for(i = 0; i < num; i++) {
        printf("%ld ", cnr[i]);
    }

    return 0;
}