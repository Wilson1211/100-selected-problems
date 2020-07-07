#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 1000000

#define target 1001

int main() {

    long int a = 0, b = 0;
    int a[N] = {};
    int i;
    int begin=1, end = 2; 
    int ptr;
    while(begin != end){
            begin = end;
            end <<= 1;
        }
        begin >>= 1;
        end >>= 1;
    }
    ptr = (begin+end)/2;
    while(begin < end) {
        if(a[ptr] == target) {
            printf("ptr: %d", ptr);
            return 0;
        }
        else if(a[ptr] < target) {
            begin = ptr;
            ptr = (begin+end+1)/2;
        }else{
            end = ptr;
            ptr = (begin+end)/2;
        }
    }
    return 0;
}