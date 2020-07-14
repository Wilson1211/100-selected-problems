#include <stdio.h>
#include <stdlib.h>

#define   MAXSIZE   1000

#define swap(a,b) {int t;t = a;a = b;b = t;}

void fix_heap(int x[], int root, int key, int bound){
    int i, tmp;
    int son, dist, left, right, mid;
    son = root + root;
    for(dist=1;son<bound;dist++)
        son = (x[son]>x[son+1])?(son<<1):(son+1)<<1;
    if(son>bound){
        dist--;
        son >> 1;
    }
    
    left = 1; right = dist;
    while(left < right){
        mid = (left+right)/2;
        if(x[root << mid] > key) left = mid+1;
        else if(x[root << mid] < key) right = mid;
        else break;
    }
    
    tmp = x[root << mid];
    x[root << mid] = key;
    for(i=mid;i>=1;i--){
        x[root << i] = tmp;
        tmp = x[root <<(i-1)];
    }
    
}


// root is the biggest
void sort(int old_x[], int n){
    int *x = old_x-1; // x[1] = old_x[0]
    int i;
    for(i = n/2;i>=1;i--)
        fix_heap(x, i, x[i], n);
    
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

