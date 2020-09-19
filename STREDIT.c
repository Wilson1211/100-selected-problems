#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(int [], int);

#define MIN(x, y, z) ((x<=y)?               \
                       ((x<=z)?(x):(z)):    \
                       ((y<=z)?(y):(z)        \
                     )

void edit(char source[], char target[], int s[], int t[], int *count) {
    int s_len = strlen(source);
    int t_len = strlen(target);
    

    int **cost;

// allocate memory
    cost = (int **)malloc(sizeof(int*)*(s_len+1));
    cost[0] = (int *)malloc(sizeof(int)*(s_len+1)*(t_len+1));
    for(int i=1;i<=s_len;i++) {
        cost[i] = cost[i-1] + t_len + 1;
    }

// initialize
    for(int j=0;j<=s_len;j++) {
        cost[j][0] = j;
    }
    for(int j=0;j<=t_len;j++) {
        cost[0][j] = j;
    }

    for(int i=1;i<=s_len;i++) {
        for(int j=1;j<=t_len;j++) {
            if(target[j] == target[i]) {
                cost[i][j] = cost[i-1][j-1];
            }else {
                cost[i][j] = MIN(cost[i-1][j]+1, cost[i][j-1]+1, cost[i-1][j-1]+2);
            }
        }
    }

    for(int i=s_len, int j=t_len, int no=0;i>=0 && j>=0;) {
        if(cost[i][j] == cost[i-1][j]+1) {
            i--;
        }else if(cost[i][j] == cost[i][j-1]+1) {
            j--;
        }else{
            s[no] = i-1; // since matrix starts at 0
            t[no] = j-1; // index of string in matrix starts at 1
            no++;
            i--;
            j--;
        }
    }
}


void edit_op(char source[], char target[], int s[], int t[], int n) {
    int s_len = strlen(source);
    int t_len = strlen(target);

    
}