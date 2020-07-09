#include <stdio.h>
#include <stdlib.h>

#define   MAXSIZE   1000
#define swap(a, b) {int t;t = a;a = b;b = t;}


split(int a[], int left, int right, int *split_pnt){
    int i;
    int pivotnum = a[left];
    (*split_pnt) = left;
    for(i=left+1;i<=right;i++){
        if(a[i] < pivotnum){
            (*split_pnt)++;
            swap(a[i], a[*split_pnt]);
        }
    }
    swap(a[left], a[*split_pnt]);
}

void median(int x[], int n){
    int mid = n/2;
    int split_pnt;
    int midian_num;
    int left = 0, right = n-1;
    while(1){
        split(x, left, right, &split_pnt);
        if(split_pnt == mid){
            break;
        }else if(split_pnt < mid){
            left = split_pnt+1;
        }else{
            right = split_pnt-1;
        }
    }

    if(n%2 != 0){midian_num = x[split_pnt];}
    else{midian_num = (x[split_pnt]+x[split_pnt-1])/2;}

    printf("\nmidian number is %d\n", midian_num);
}

void main(void)
{
     int  input[MAXSIZE+1];
     int  n, i;
     char line[100];

     printf("\nFind Mediam Program Testing Driver for Random Data");
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

//     sort(input, n);
    median(input, n);
     printf("\n\nSorted Data :");
     for (i = 0; i < n; i++) {
          if (i % 10 == 0)  printf("\n");
          printf("%6d", input[i]);
     }
}