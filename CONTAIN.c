#include <stdio.h>
#include <stdlib.h>

// this problem needs to show index of contained intervals

#define YES 1
#define NO  0


void sort(int [], int [], int);
void qsort(int [], int [], int, int);
void split(int [], int [], int, int, int *);
void swap(int *, int *);

void containment(int left[], int right[], int mark[], int n){
    int i;
    int current_right_end;
    current_right_end = right[0];

    sort(left, right, n);
    for(i=1;i<n;i++){
        if(right[i] <= current_right_end){
            mark[i] = YES;
        }else{
            mark[i] = NO;
            current_right_end = right[i];
        }

    }
}

void sort(int left[], int right[], int n){
    qsort(right, left, 0, n-1)
}

void qsort(int right[], int left[], int first, int last){
    int 
    split()
}


void split(int )