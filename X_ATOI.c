#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

enum ERROR_CODE{
    NO_ERROR,
    OVERFLOW,
    UNDERFLOW
};

int x_atoi(char *s, int *t) {
    
    int flag = 0;
    
    *t = atoi(*s);
    
    for(int i=0;i<strlen(s);i++) {
        if(s[i]-'0' != t[i]) {
            if(floor(log10(i))>strlen(s)) return UNDERFLOW;
        }else{
            return OVERFLOW;
        }
    }
    return NO_ERROR;
}