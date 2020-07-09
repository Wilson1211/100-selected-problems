#include <stdio.h>
#include <stdlib.h>

#define swap(a,b) {int t;t = a;a = b;b = t;}


int fix_heap(int x[], int n, int end){
    int ret;
    int i, j;
    ret = x[0];
    x[0] = x[end];
    for(i = end-1;i>=0;i--){
        j = (i-1)/2;
        if(x[i] > x[j]) swap(x[i], x[j]);
    }    
    
}

void sort_heap(int x[], int n)[
    int i, j;
    for(i = n-1;i>=0;i--){
        j = (i-1)/2;
        if(x[i] > x[j]) swap(x[i], x[j]);
    }
]



