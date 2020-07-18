#include <stdio.h>
#include <stdlib.h>

#define   MAXSIZE   1000

#define swap(a,b) {int t;t = a;a = b;b = t;}

void merge_sort(int [], int, int, int);

void sort(int x[], int n){
    merge_sort(x, n, 0, n);
}

void merge_sort(int x[], int n, int lft, int rht){
    if(rht == lft) return;
    if(rht-1==lft){
        if(x[rht]<x[lft]) swap(x[rht], x[lft]);
        return;
    }   
    
    int i, ptr1, ptr2, mid;
    int *y = malloc((rht-lft+1)*sizeof(int));
    mid = (rht+lft)/2;
    i=0;
    merge_sort(x, n, lft, mid);
    merge_sort(x, n, mid+1, rht);
    ptr1 = lft;ptr2 = mid+1;
    while(ptr1<=mid&&ptr2<=rht){
        if(x[ptr1]>x[ptr2]) y[i++] = x[ptr2++];
        else y[i++] = x[ptr1++];
    }
    while(ptr1<=mid){
        y[i++] = x[ptr1++];
    }
    while(ptr2<=rht){
        y[i++] = x[ptr2++];
    }
    for(i=0;i<(rht-lft+1);i++){
        x[lft+i] = y[i];
    }
    free(y);
    return;
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

     sort(input, n-1);
     printf("\n\nSorted Data :");
     for (i = 0; i < n; i++) {
          if (i % 10 == 0)  printf("\n");
          printf("%6d", input[i]);
     }
}

