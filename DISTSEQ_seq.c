#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE    5


void arr(int a[], int index, int n) {
    if(index >= 4) {
        for(int j=0;j<SIZE;j++) printf("%d", a[j]);
        printf("\n"); 
        return;
    }

    for(int i=1;i<4;i++) {
        a[index] = i;
        //if(index == 4) {
        //    printarr(a);
        //}
        arr(a, index+1, n);
    }
}

void main() {

    int a[SIZE];

    memset(a, 0, SIZE);

    arr(a, 0, SIZE);


    return;
}