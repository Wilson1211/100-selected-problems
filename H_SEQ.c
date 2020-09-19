#include <stdio.h>
#include <stdlib.h>
#include <string.h>



bool h_sequence(char x[]){
    int count;
    int length = strlen(x);
    count = 1;
    
    for(int i=0;i<length;i++){
        if(x[i] == '1') count++;
        else count--;
        if(count < 0) return FALSE;
    }
    if(count == 0) return TRUE;

    return FALSE;
}