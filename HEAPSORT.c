#include <stdio.h>
#include <stdlib.h>

#define   MAXSIZE   1000

#define swap(a,b) {int t;t = a;a = b;b = t;}
/*
void fix_heap_sort(int x[], int begin, int length){
    int i = begin, j;
    j = 2*i+2;
    while(j<=length){
        if(x[i]>x[j]) {swap(x[i], x[j]);}
        else if(x[i] > x[j-1]) {swap(x[i], x[j-1]);}
        else {break;}
        j = j*2+2;
    }
}


int fix_heap(int x[], int end, int target){
    int ret;
    int i, j;
    ret = x[end];
    x[end] = x[target];
    x[target] = ret;
    fix_heap_sort(x, target, end-1);
    return ret;
}
*/

void fix_heap(int x[], int target, int n){
    int left, right, max;
    left = target*2+1;
    right = target*2+2;
    if(n < (left+1)) {return;}
    else if((n-1) < right){
        if(x[target]<x[left]) swap(x[target], x[left]);
        return;
    }
    max = (x[left]>x[right])?left:right;
    if(x[target]<x[max]) {
        swap(x[target], x[max]);
        fix_heap(x, max, n);
    }
}



// root is the biggest
void sort_heap(int x[], int n){
    int count = (n-1)/2;
    for(;count>=0;count--){
        fix_heap(x, count, n);
    }
}



void main(void)
{
     int  input[MAXSIZE+1];
     int  n, i;
     char line[100];

     printf("\nSort Program Testing Driver for Random Data");
     printf("\n===========================================");
     printf("\n\nHow many data items ( <= 1000) ? ");
     gets(line);
     n = atoi(line);

     srand((unsigned) clock());
     printf("\nGenerated Data :");
     for (i = 0; i < n; i++) {
          if (i % 10 == 0)  printf("\n");
          input[i] = rand()%4000;
          printf("%6d", input[i]);
     }

     sort_heap(input, n);
     printf("\n\nSorted Data :");
     for (i = 0; i < n; i++) {
          if (i % 10 == 0)  printf("\n");
          printf("%6d", input[i]);
     }
}

