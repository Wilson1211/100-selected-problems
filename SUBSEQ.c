#include <stdio.h>
#include <stdlib.h>


bool subseq(char text[], char pat[]){
    int t_ptr, p_ptr;

    int t_length = strlen(text);
    int p_length = strlen(pat);
    
    t_ptr = 0; p_ptr = 0;
    while(t_ptr < t_length && p_ptr < p_length){
        if(pat[p_ptr] == text[t_ptr]) p_ptr++;
        t_ptr++;
    }
    if(p_ptr >= p_length) return true;
    return false;
}