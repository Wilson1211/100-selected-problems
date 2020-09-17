#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// given the pattern pat[], setup builds up the failure function table fail[]
// fail[] records the index 
void setup(char pat[], int fail[]){
    char *e;
    int i = 0;

    fail[0] = -1;
    e = pat+1;
    while(e != 'EOF') {
        if(pat[fail[i]+1] == pat[i]) fail[i] = fail[i-1]+1;
        else{
            for(j=fail[i-1];j>=0 && pat[j+1] != pat[i];j=fail[j]);
            if(j<0){
                fail[i] = -1;
            }else{
                fail[i] = j+1;
            }
        }
        e++;
        i++;
    }
}


// The KMP pattern search routine
int KMP(char text[], char pat[], int fail[]){
    
    int t_length = strlen(text);
    int p_length = strlen(pat);
    int p, t;
    setup(pat, fail);

    for(p = t = 0;t < t_length && p < p_length;){
        if(pat[p] == text[t]) { p++; t++;}
        else{
            if(p >= 0){
                p = fail[p-1]+1;
            }else{
                t++;
            }
        }
    }

    return (p >= p_length)?(t-p_length):-1;

}


