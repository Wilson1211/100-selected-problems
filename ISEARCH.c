#include <stdio.h>
#include <stdlib.h>

#define N 6

int isearch(int a[], int begin, int end, int index) {
    int i;
    while(begin < end) {
        if(a[index] == (index+1)) {return index+1;}
        if(a[index] < (index+1)) {
            begin = index;
            index = (begin+end+1)/2;
        }else{
            end = index;
            index = (begin+end)/2;
        }
    }
    return -1;
}

int main() {
    int begin = 0, end = N-1, ret;
    int i;
    int a[N] = {-2, -1, 3, 7, 8, -2};

    ret = isearch(a, begin, end, (begin+end)/2);
    printf("%d\n", ret);

    return 0;
}