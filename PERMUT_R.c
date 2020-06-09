#include <stdio.h>
#include <stdlib.h>

int N = 4;

void permute(int a[], int end) {
    int i;
    int tmp = a[end];
    for(i = end;i>0;i--) {
        a[i] = a[i-1];
    }
    a[0] = tmp;
}

void print(int a[]){
    int i;
    for(i=0;i<N;i++) printf("%d", a[i]);
    printf("\n");
}


int main() {
    int i, j, count, k;
    int a[4];
    for(i = 0; i < N; i++) a[i] = i+1;
    for(i =N-1;i >= 0; i--) {
        count = i;
        while(count--) {
            print(a);
            for(j = 0;j < N;j++) {
                permute(a,N-1);
                print(a);
            }
            k = N-1;
            while(a[k] == k+1) permute(a, --k);
            //if(a[N-1] == N) permute(a, i-1);
        }
    }


    return 0;
}