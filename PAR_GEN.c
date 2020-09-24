#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX_SIZE 20

void display(char a[], int n) {
    for(int i=0;i<n;i++) {
        printf("%c", a[i]);
    }
    printf("   ");
}

void par_gen(int L, int R, char arr[], int n) {
    if(L==0) {
        if(R==0) {
            display(arr, n);
            return;
        }
        for(int i=0;i<R;i++) {
            arr[n++] = ')';
        }
        display(arr, n);
        printf("  ");
        return;
    }
    if(L==R) {
        arr[n] = '(';
        par_gen(L-1,R, arr, n+1);
        return;
    }
    
    arr[n] = '(';
    par_gen(L-1, R, arr, n+1);
    arr[n] = ')';
    par_gen(L, R-1, arr, n+1);
}



int main() {
    char arr[MAX_SIZE] = "";
    par_gen(3, 3, arr, 0);
}