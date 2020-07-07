#include  <stdio.h>
#include  <stdlib.h>
#include  <time.h>

#define   MAXSIZE   1000

void swap(int *a, int *b){
    if(a == b) return;
    if(*a == 0 | *b == 0){
        printf("QQ\n");
    }
    *a = (*a)^(*b);
    *b = (*a)^(*b);
    *a = (*a)^(*b);
    
    if(*a == 0 | *b == 0){
        printf("GG\n");
    }
}

void q_sort(int x[], int st, int end){
    if(st == end) return;
    if((end-st)==1){
        if(x[st]>x[end]){
            int tmp;
            tmp = x[st];
            x[st] = x[end];
            x[end] = tmp;
        }
        return;
    }
    int pivotnum = x[st];
    int pivot = st;
    int i, j, k;
    for(i = st+1;i <= end;i++){
        if(x[i]<pivotnum){
            pivot++;
            swap(&x[pivot], &x[i]);
        }
    }
    if(pivot == st){
        q_sort(x, st+1, end);
    }else{
        swap(&x[st], &x[pivot]);
        q_sort(x, st, pivot-1);
        if(pivot < end) q_sort(x, pivot+1, end);
    }
    return;
}

void  sort(int x[], int n){
    q_sort(x, 0, n-1);
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