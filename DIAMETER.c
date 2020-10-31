#include <stdio.h>
#include <stdlib.h>


int main() {
    int arr[] = {1,1,1,2,1,1,2};
    int N = 7;
    int aptr[100];
    int sum = 0;
    int tmp_sum1, tmp_sum2;
    int dia, dia_count;

    for(int i=0;i<N;i++) {
        sum += arr[i];
    }
    dia = sum;
    dia_count = 0;

    for(int i=0;i<N;i++) {
        tmp_sum2 = 0;
        
        int j = i;

        tmp_sum1 = arr[i];
        tmp_sum2 = sum-tmp_sum1;

        while(tmp_sum1 <= tmp_sum2) {
            if(dia > (tmp_sum2 - tmp_sum1)) {
                dia = tmp_sum2 - tmp_sum1;
                dia_count = 0;
                aptr[dia_count++] = i;
                aptr[dia_count] = j;
                printf("tmp_sum1: %d, tmp_sum2: %d, dia: %d, i: %d, j: %d\n", tmp_sum1, tmp_sum2, dia, i, j);
            }else if(dia == (tmp_sum2-tmp_sum1)) {
                aptr[++dia_count] = i;
                aptr[++dia_count] = j;
                printf("tmp_sum1: %d, tmp_sum2: %d, dia: %d, i: %d, j: %d\n", tmp_sum1, tmp_sum2, dia, i, j);
            }
            j++;
            j=j%N;
            tmp_sum1 += arr[j];
            tmp_sum2 = sum-tmp_sum1;
        }
        if(dia > (tmp_sum1 - tmp_sum2)) {
            dia = tmp_sum1 - tmp_sum2;
            dia_count = 0;
            aptr[dia_count++] = i;
            aptr[dia_count] = j;
            printf("tmp_sum1: %d, tmp_sum2: %d, dia: %d, i: %d, j: %d\n", tmp_sum1, tmp_sum2, dia, i, j);
        }else if(dia == (tmp_sum1-tmp_sum2)) {
            aptr[++dia_count] = i;
            aptr[++dia_count] = j;
            printf("tmp_sum1: %d, tmp_sum2: %d, dia: %d, i: %d, j: %d\n", tmp_sum1, tmp_sum2, dia, i, j);
        }
    }

    for(int i=0;i<dia_count;i+=2) {
        printf("aptr[%d] - aptr[%d]\n", aptr[i], aptr[i+1]);
    }
    return 0;
}