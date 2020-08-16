#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NOT_FOUND   -1

void get_jump(unsigned char [], int []);
int BM(unsigned char [], unsigned char []);


int BM(unsigned char text[], unsigned char pat[]){
    int jump_tab[256];
    int t_len = strlen(text);
    int p_len = strlen(pat);

    int i, t, p;
    t = p_len;
    p = 0;
    i = 0;

    get_jump(pat, jump_tab);

    while(t<t_len){
        i = 0;
        for(p=p_len-1;p>=0;p--){
            if(pat[p] != text[t-i]){
                t += jump_tab[text[t]];
                break;
            }
            i++;
        }
        if(i == p_len-1){
            return (t - i);
        }
    }

    return NOT_FOUND;
}

void get_jump(unsigned char pat[], int jump_tab[]){
    int length = strlen(pat);

    for(int i=0;i<256;i++){
        jump_tab[i] = length;
    }
    for(int i=0;i<length;i++){
        jump_tab[pat[i]] = length-1-i;
    }
}

