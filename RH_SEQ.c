#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
bool RH_SEQ(unsigned char text[]){

    char substr[] = "0";
    int substr_size = strlen(substr);
    int t_size, p_size;
    char *ptr = text;

    t_size = strlen(text);
    char pat[] = "100";
    p_size = strlen(pat);

    int i;
    i = 0;

    while(1){
        ptr = strstr(ptr, pat);
        if(ptr == NULL) break;
        else{
            memset(ptr, substr, substr_size);
        }
        i++;
    }

    if(text != "0"){
        return 0;
    }else{
        return 1;
    }

}
*/

#define YES     1
#define NO      0
int h_seq(char []);
int cursor;

// the control routine
int h_sequence(char x[]){
    int length = strlen(x);
    cursor = 0;

    if(h_seq(x) == YES){
        if(cursor == length - 1){
            return YES;
        }
    }

    return NO;
}


// the working routine by using recursive decent
int h_seq(char x[]){

    int length = strlen(x);
    if(cursor >= length) return NO;

    switch(x[cursor]){
        case 0: return YES;
        case 1:
            cursor++;
            if(h_seq(x) == YES){
                cursor++;
                if(h_seq(x) == YES){
                    return YES;
                }
            }
            return NO;
        default:
            break;        
    }
    return NO;
}

