#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define M_PI 3.14159265358979323846

void main() {
    srand(time(0));

    int c = 0;
    double tmp;
    double L = 100000, D = 100000;

    for(int i=0;i<10000;i++) {
        tmp = fmod(rand(), D) + L*sin(fmod(rand(), 2*M_PI));
        if(tmp <= 0 || tmp >= D) c++;
    }
    printf("%f\n", c/10000.0);
}