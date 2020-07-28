#include <stdio.h>
#include <stdlib.h>
//#include <math.h>

// this problem only needs to count the maximum people 

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
