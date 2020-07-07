#include <stdio.h>
#include <stdlib.h>

#define MATRIXSIZE 10
typedef int MATRIX[MATRIXSIZE][MATRIXSIZE];

void two_square(MATRIX mat, int* index_x , int* index_y, int k, int target){
    int i=0, j=n-1;
    for(i=0,j=n-1;i<n && j>=0;){
        if(mat[i][j] == target){
            index_x = i;
            index_y = j;
            return;
        }
        if(mat[i][j] < target){
            j--;
        }else{
            i++;
        }


    }


    
}