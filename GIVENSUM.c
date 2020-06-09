#include <stdio.h>
#include <stdlib.h>


int a, b;
int target = 4;
int givensum(int &sum, int N) {
    while(b <= N) {
        while(sum > target) {
            sum -= a;
            a++;
        }
        if(sum == target) return 1;
        while(sum < target) {
            sum += (++b);
        }
    }
    return 0;
}

int main(){
    int i;
    a = 1;
    b = a+1;
    int sum = a+b;
    while(b <= (target+1)/2) {
        if(givensum(sum, (target+1)/2)) {
            printf("%d - %d\n", a, b++);
            sum += (b - (a++));
        }
    }
    return 0;
}