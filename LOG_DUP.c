/**************************

There are log(n) different values, each appears n/log(n) times

**************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define   MAXSIZE   1000
#define   MIN(x, y) {(x<=y)?x:y}
#define   SWAP(x, y) {int t; t = x;x = y;y = t;}

int *in1_data, *in1_count, *in2_data, *in2_count, *out_data, *out_count;
int number;

void swap(int* a, int* b){
    if(a == b) return;
    *a = (*a)^(*b);
    *b = (*a)^(*b);
    *a = (*a)^(*b);
}


// log_sort cuts input array into segments with size log(n) and sort each segment
void LOG_sort(int [], int, int);

// merge two sorted segments which have no duplicate elements 
void LOG_merge(int [], int, int);

// compress two sorted segments into data/counting form 
// such that there's no duplicate elements
int compress(int [], int, int *, int *);
int LOG_expand(int []);
void sort(int [], int, int);


void LOG_sort(int x[], int begin, int end){
     int logn = (int)(log2(number)+0.5);
     int i;



     for(i=begin;i<end;i+= logn){
          sort(x, i, i+logn-1);
     }


     in1_data = (int*) malloc(sizeof(int)*logn);
     in1_count = (int*) malloc(sizeof(int)*logn);
     out_count = (int*) malloc(sizeof(int)*logn);

     in2_data = (int*) malloc(sizeof(int)*logn);
     in2_count = (int*) malloc(sizeof(int)*logn);
     out_count = (int*) malloc(sizeof(int)*logn);

     number = LOG_merge(x, n, logn);
     LOG_expand(x);

     free(in1_data);
     free(in1_count);
     free(in2_data);
     free(in2_count);
     free(out_data);
     free(out_count);


}



int LOG_merge(int x[], int n, int seg_size){
     int no1, no2; // number of two elements in two input
     int start, len; // start is the cursor

     no1 = compress(x, seg_size, in1_data, in1_count);





}

int compress(int x[], int n, int *in1, int *in2){

}

void LOG_expand(int x[]){
     int i, j, total;

     total = 0;
     for(i=0;i<number;i++){
          for(j=0;j<in1_count[i];j++){
               x[total++] = in1_data[i];
          }
     }
}



// use qsort_l
void sort(int input[], int begin, int end){
     int i, negnum;
     int pivot, pivot_num;


     while(negnum <= end){
          pivot = negnum;
          pivot_num = input[negnum];

          for(i=negnum+1;i<=end;i++){
               if(input[i]<pivot_num){
                    pivot++;
                    swap(&input[i], &input[pivot]);
               }
          }

          swap(&input[pivot], &input[negnum]);
          input[pivot] = 0-input[pivot];

          while(input[negnum]<0 && negnum <= end) negnum++;
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

     //sort(input, n);
     printf("\n\nSorted Data :");
     for (i = 0; i < n; i++) {
          if (i % 10 == 0)  printf("\n");
          printf("%6d", input[i]);
     }
}