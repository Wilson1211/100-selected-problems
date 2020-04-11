#include <stdio.h>
#include <stdlib.h>

int headtail(int *x) {
    int i, j, k, count = 0;
    int leny = sizeof(x)/sizeof(x[0]);
    int bptr = 0, eptr = leny - 1;
    int bcount = x[bptr], ecount = x[eptr];
    while(bptr < eptr){
        if(bcount > ecount) ecount += x[--eptr];
        else if(bcount < ecount) bcount += x[++bptr];
        else{
            count++;
            bcount += x[++bptr];
        }
    }
    return count;
}