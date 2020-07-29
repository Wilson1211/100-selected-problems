#include <stdio.h>
#include <stdlib.h>
//#include <math.h>

// this problem only needs to count the maximum people in lobby 
// at the same time

#define   MAXSIZE   1000
#define   IN        1
#define   OUT       0

struct table{
    int clock;
    int status;
};

typedef struct table TABLE;

void sort(TABLE [], int);
void qsort(TABLE [], int, int);
void split(TABLE [], int, int, int *);
void swap(TABLE *, TABLE *);


void maxvisit(int left[], int right[], int n){
    int i, j, k;
    
    
    TABLE table = malloc(sizeof(table)*2*n);
    
    for(i=0;i<n;i++){
        table[i]->clock = left[i];
        table[i]->status = IN;
        table[i+n]->clock = right[i];
        table[i+n]->status = OUT;
    }

    sort(table, 2*n);
}



