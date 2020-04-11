#include <stdio.h>
#include <stdlib.h>
//#include <math.h>

int pow(int num, int n){
    for(int i = 0; i < n-1; i++){
        num *= num;
    }
    return num;
}


bool arms1(int num){
    int a[3];
    a[0] = (num%1000)/100;
    a[1] = (num%100)/10;
    a[2] = (num%10);
    if(pow(a[0])+pow(a[1])+pow(a[2]) == num) return 1;
    
    return 0;
}