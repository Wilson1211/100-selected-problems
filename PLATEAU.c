#include <stdio.h>
#include <stdlib.h>

int main(){
    int prev = -100;
    int x;
    int max = 0, count = 0;
    while (scanf("%d", &x))
    {
        if(x == prev) count++;
        if(count > max) max = count;
        prev = x;
    }
    
    return max;
}