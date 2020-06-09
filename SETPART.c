#include <stdio.h>
#include <stdlib.h>

#define N 4

void setpart(int a[], int max, int idx) {
    int i;
    if(idx == N+1) {
        for(i=0;i<N;i++) printf("%d", a[i]);
        printf("\n");
        return;
    }
    
    int mm = max+1;
    int tmp_max;
    if(mm > idx) mm = idx;
    for(i=1;i<=mm;i++) {
        a[idx-1] = i;
        tmp_max = (i>max)?i:max;
        setpart(a, tmp_max, idx+1);
    }



}

int main() {
    int a[N] = {};
    setpart(a, 1, 1);
}