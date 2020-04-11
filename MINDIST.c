#include <stdio.h>
#include <stdlib.h>

int mindist(int *x, int* y) {
    int i, j = 0, k, max = 1000000, count = 0;
    int lenx = sizeof(x)/sizeof(x[0]), leny = sizeof(y)/sizeof(y[0]);
    
    for(i = 0; i < lenx; i++) {
        while(x[i] >= y[j] && j < leny) j++;
        if(j == leny) {
            max = ((x[i]-y[j-1]) < max)? x[i]-y[j-1]:max;
            return max;
        }
        max = ((y[j] - x[i]) < max)? y[j]-x[i]:max;
        if(j != 0) max = ((x[i] - y[j-1]) < max)? x[i]-y[j-1]:max;    
    }
    return max;

}