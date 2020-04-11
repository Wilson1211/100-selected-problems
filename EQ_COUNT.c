#include <stdio.h>
#include <stdlib.h>

#define maxn 10000

int eq_count(int *f, int *g){
    int i, count = 0, max, len_size;
    int *l;
    len_size = sizeof(f)/sizeof(f[0]);
    max = f[len_size-1];
    l = (int *)malloc(max);
    for(i = 0; i < len_size; i++) l[f[i]] = 1;
    len_size = sizeof(g)/sizeof(g[0]);
    for(i = 0; i < len_size; i++) if(l[g[i]] == 1) count++;

    return count;
}