#include <stdio.h>
#include <stdlib.h>


void st_nd(int a[], int begin, int end, int *fst, int *snd) {
    int i, j, k, l;
    if((end-begin)==1) {
        *fst = (a[end]>a[begin])?a[begin]:a[end];
        *snd = a[end]^a[begin]^(*fst);
        return;
    }else if((end-begin)==2){
        if(a[begin] < a[begin+1]) {
            *fst = a[begin];
            *snd = a[begin+1];
        }else{
            *fst = a[begin+1];
            *snd = a[begin];
        }
        if(a[end] < *fst) {
            *snd = *fst;
            *fst = a[end];
        }else if(a[end] < *snd) {
            *snd = a[end];
        }
        return;
    }
    st_nd(a, begin, (begin+end)/2, &i, &j);
    st_nd(a, (begin+end)/2+1, end, &k, &l);
    if(i < k) {
        *fst = i;
        if(k < j) *snd = k;
        else *snd = j;
        return;
    }else{
        *fst = k;
        if(i < l) *snd = i;
        else *snd = l;
        return;
    }
}

int main() {
    int a[] = {1,92,32,45,52,67,79,58,9};
    int fst, snd;
    st_nd(a, 0, 8, &fst, &snd);
    printf("least: %d, second least: %d\n", fst, snd);
    return 0;
}