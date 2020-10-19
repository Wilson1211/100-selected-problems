#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    int N = 10;
    int *arr;
    int *check_arr;
    int begin = 0, end, sum = 0;
    int flag = 0;
    //scanf("%d", &N);
    arr = (int *)malloc(sizeof(int)*N);
    
    srand(time(0));
    for(int i=0;i<N;i++) {
//        scanf("%d", &arr[i]);
        arr[i] = rand()%40;
        sum += arr[i];
        //printf("%3d ", arr[i]);
    }
    if(sum %2 != 0) {
        printf();
    }

    while(flag != 2) {
        for(int i=0;i<N;i++) {
            
        }
    }


    return 0;
}