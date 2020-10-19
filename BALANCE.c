#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main() {
    int N = 10;
    int *arr;
    int *check_arr;
    int max_len = 0;
    //scanf("%d", &N);
    arr = (int *)malloc(sizeof(int)*N);
    check_arr = (int *)malloc(sizeof(int)*N);
    
    srand(time(0));
    for(int i=0;i<N;i++) {
//        scanf("%d", &arr[i]);
        arr[i] = 20-rand()%40;
        printf("%3d ", arr[i]);
    }

    check_arr[0] = (arr[0]>0)?1:-1;
    if(arr[0] == 0) check_arr[0] = 0;
    for(int i=1;i<N;i++) {
        check_arr[i] = check_arr[i-1];
        check_arr[i] += (arr[i]>0);
        check_arr[i] -= (arr[i]<0);
        max_len = (check_arr[i]==0)?i+1:max_len;
    }
    
    for(int i=0;i<N-1;i++) {
        for(int j=N-1;j>i;j--) {
            if(check_arr[i] == check_arr[j]) {
                if(max_len < j-i) max_len = j-i;
                break;
            }
        }
    }
    
    printf("\n");
    for(int i=0;i<N;i++){
        printf("%3d ", check_arr[i]);
    }
    printf("\nlongest length: %d\n", max_len);
    
    return 0;
}