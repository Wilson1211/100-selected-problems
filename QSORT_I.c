#include <stdio.h>
#include <stdlib.h>

#define   MAXSIZE   1000

void swap(int* a, int* b){
    if(a == b) return;
    *a = (*a)^(*b);
    *b = (*a)^(*b);
    *a = (*a)^(*b);
}


void  sort(int x[], int n){
    int i ,j, k;
    int pivotnum, pivot;
    pivot = 0;
    int negnum = 0;
    while(negnum < n){
        pivotnum = x[negnum];
        pivot = negnum;
        for(i=negnum;i<n && x[i]>0;i++){
            if(x[i]<pivotnum){
                pivot++;
                swap(&x[i], &x[pivot]);
            }
        }
        swap(&x[negnum], &x[pivot]);
        x[pivot] = 0-x[pivot];

        while(x[negnum] < 0 && (negnum < n)) negnum++;
    }    


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

     sort(input, n);
     printf("\n\nSorted Data :");
     for (i = 0; i < n; i++) {
          if (i % 10 == 0)  printf("\n");
          printf("%6d", input[i]);
     }
}