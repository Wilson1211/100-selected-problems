/* ------------------------------------------------------ */
/* PROGRAM  sorttest :                                    */
/*    This is a sample program to drive various sorting   */
/* function testing.  It generates positive random data,  */
/* puts them into an array and finally calls the sorting  */
/* function named sort().  NOTE that for bucket sort, you */
/* have to change the data type from 'int' to 'unsigned'. */
/* ------------------------------------------------------ */

#include  <stdio.h>
#include  <stdlib.h>
#include  <time.h>
#include <string.h>

#define   MAXSIZE   1000
#define   SIZE      sizeof(int)/sizeof(char)

#define   YES    1
#define   NO     0
//#define __sol__

#if defined(__sol__)

void  sort(int input[], int n)
{
     int  current, pos;
     int  low, high, mid;
     int  x;

     for (current = 1; current < n; current++) {
          x   = input[current];
          pos = -1;           /* pos=-1 means DON'T move  */
          if (x < input[0])   /* insert before head ?     */
               pos = 0;       /* YES, set pos to 0.       */
          else if (x <= input[current-1]) { /* bin search */
               low  = 0;      /* low index.               */
               high = current - 1;  /* high index         */
               while (high - low > 1) { /* stop?          */
                    mid = (low + high) / 2; /* the mid pt */
                    if (x >= input[mid]) 
                         low = mid;  /* try right         */
                    else
                         high = mid; /* try left          */
               }
               pos = low + 1;
          }
          if (pos >= 0) {     /* move a block             */
               memmove((void *) &input[pos+1], (void *) &input[pos], 
                       SIZE*(current-pos));
               input[pos] = x;
          }
     }
}
#else
void sort(int input[], int n){
     int i, j, k;
     int begin, end, tmp=1, x, pos=0;
     for(i=1;i<n;i++){
          begin = 0;
          end = i-1;
          x = input[i];
          pos = -1;
          if(x < input[0]) pos = 0;
          else if(x <= input[i-1]){
               while(begin < (end-1)){
                    tmp = (begin+end)/2;
                    if(x < input[tmp]) {
                         end = tmp;
                    }
                    else{
                         begin = tmp;               
                    }
               }
               pos = begin+1;
          }
          if(pos>=0){
               memmove(&input[pos+1], &input[pos], SIZE*(i-pos));
               input[pos] = x;
          }
     }
}
#endif

int main(void)
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
          input[i] = rand()%2000;
          printf("%6d", input[i]);
     }
     printf("\n");
     sort(input, n);
     printf("\n\nSorted Data :");
     for (i = 0; i < n; i++) {
          if (i % 10 == 0)  printf("\n");
          printf("%6d", input[i]);
     }
     return 0;
}