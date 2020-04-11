#include <stdio.h>
#include <stdlib.h>

#define maxn 100

int main(){
    int  i = 0, j = 0 ,k1 = 0, k2 = 0;
    int count = 0;
    int f[maxn], g[maxn];
    while(scanf("%d", &f[i++])){}
    k1 = i;
    i = 0;
    while(scanf("%d", &g[i++])){}
    k2 = i;
    for(i = 0; i < k2; i++) {
        for(j = 0; j < k1; j++) {
            if(f[j] > g[i]) {
                count += (k1 - j + 1);
                break;
            }
        }
    }
    return 0;
}