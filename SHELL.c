#include  <stdio.h>
#include  <stdlib.h>
#include <math.h>
#include  <time.h>

#define   MAXSIZE   1000

#define EQN(x) ((4*x+3)*x+1)

void  sort(int x[], int n){
    int power = log((-3+sqrt(16*n-7))/8)/log(2.0);
    power = 1<<(power);
    int gap, tmp;
    gap = EQN(power);
    int i, j, k;
    /*
    while(power>=0){
        for(i=n;i>=0;i-=gap){
            for(j=i-gap;j>=0;j-=gap){
                if(x[j] > x[i]){
                    tmp = x[j];
                    x[j] = x[i];
                    x[i] = tmp; 
                }
            }
        }
        if(power > 0)power >>= 1;
        else break;
        gap = EQN(power);
    }    */
    
    

    while(gap > 1){
        gap = EQN(power);
        for(i=gap;i<n;i++)
            for(j=i-gap;j>=0&&x[j]>x[j+gap];j-=gap){
                tmp = x[j];
                x[j] = x[j+gap];
                x[j+gap] = tmp;
            }
        power >>= 1;
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