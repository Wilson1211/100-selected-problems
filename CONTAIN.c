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
    if(first >= last) return;
    int split_num;
    split(left, right, first, last, &split_num);
    qsort(left, right, first, split_num-1);
    qsort(left, right, split_num+1, last);
}


void split(int left[], int right[], int first, int last, int *split_num){
    int i, j, k;
    int pivot, pivot_num;
    pivot = first;
    pivot_num = left[first];
    for(i=first+1;i<=last;i++){
        if(left[i] < pivot_num){
            pivot++;
            swap(left[i], left[pivot]);
            swap(right[i], right[pivot]);
        }
    }
    swap(left[first], left[pivot]);
    swap(right[first], right[pivot]);
}

void swap(int *a, int *b){
    int t;
    t = *a;
    *a = *b;
    *b = t;
}