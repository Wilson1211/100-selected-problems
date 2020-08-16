#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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