#include <stdio.h>
#include <stdlib.h>

void matrix_square(int *a, int *b, int *c, int *d) {
    int tmp_a = *a, tmp_b = *b, tmp_c = *c, tmp_d = *d;
    *a = tmp_a * tmp_a + tmp_b * tmp_c;
    *b = tmp_b * (tmp_a + tmp_d);
    *c = tmp_c * (tmp_a + tmp_d);
    *d = tmp_b * tmp_c + tmp_d * tmp_d;
    return;
}

void matrix_mul(int *a, int *b, int *c, int *d) {
    int tmp_a = *a, tmp_b = *b, tmp_c = *c, tmp_d = *d;
    *a = tmp_a + tmp_b;
    *b = tmp_a;
    *c = tmp_c + tmp_d;
    *d = tmp_c;
    return;
}

int fib(int n){
    int i1 = 1, i2 = 1, i3 = 1, i4 = 0; 
    int cnt = 0;
    int a[100] = {};
    while(n != 1){
        a[cnt++] = n % 2;
        n /= 2;
    }
    while(cnt) {
        matrix_square(&i1, &i2, &i3, &i4);
        if(a[--cnt] == 1){
            matrix_mul(&i1, &i2, &i3, &i4);
        }
    }
    return i1;
}

void main(){
    int i, j = 2;
    while(j < 11){
        i = fib(j);
        printf("%d\n", i);
        j++;
    }
    return;
}