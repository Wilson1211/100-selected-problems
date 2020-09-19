#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void    change(int [], int *);
void    extend(int [], int *);
int     check(int [], int);
void    output(int [], int);

// The given input is n and seq[] array is the array to store generated sequence
void seq_gen(int seq[], int n) {
    
    int i = 1;
    int no;

    seq[0] = 1;
    seq[1] = 2;
    no = 1;
    while(no >= 0) {
        if(check(seq, i)) {
            if(no == n-1) {
                output(seq, no);
                change(seq, &no);
            }else {
                extend(seq, &no);
            }
        }else {
            change(seq, &no);
        }
    }
}

//  given seq[] and index of it, no, this function finds the last digit s.t. 
//  has a chance that could be increased
void change(int seq[], int *no) {
    for(;seq[*no] == 3;(*no)--);
    seq[*no]++;
}

//  put a '1' into the position next to the last
void extend(int seq[], int *no) {
    seq[(*no)++] = 1;
}

//  this fnt checks to see if the seq has a consecutive duplicated substr
int check(int seq[], int no) {
    int max_len = no/2;
    int flag;
    for(int i=0;i<max_len;i++) {
        flag = 0;
        for(int j=0;j<=i;j++) {
            if(seq[no-j] != seq[no-j-(i+1)]) {
                flag = 1;
                break;
            }
        }
        if(flag == 0) return 0;
    }
}

//  display the generated seq
void output(int seq[], int n) {
    for(int i=0;i<n;i++) {
        printf("%d", seq[i]);
    }
    printf("\n");
}
