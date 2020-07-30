#include <stdio.h>
#include <stdlib.h>

#define MAXLENGTH   1000
#define YES         1
#define NO          0

void parcount(char line[], char error[], int *sw){
    int location[MAXLENGTH]; // -1 means redundant left bracket -2 means right bracket
    int i, j, k;
    int count;

    *sw = NO;

    i=0;
    count = -1;
    while(line[i]!='\0'){
        if(line[i] == '(') {
            location[++count] = i;
        }
        else if(line[i] == ')') {
            if(count<0){
                error[i] = '?';
                *sw = YES;
            }else{
                count--;
            }
        }
        if(count<0) error[i] = '?';
        i++;
    }

    error[i] = '\0';

    i=0;
    while(count>0){
        *sw = YES;
        for(i=0;i<count;i++){
            error[location[i]] = '$';
        }
    }

}