#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int subsequence(char [], char [], int [], int);

int max_repetition(char text[], char pat[], int loc[]) {
    int t_len = strlen(text);
    int p_len = strlen(pat);    
    
    int i, j;

    int l, r, m;
    l = 1; r = t_len/t_len;
    m = (l+r)/2;

    while(l<r){
        if(subsequence(text, pat, loc, m)){
            l = m+1;
        }else{
            r = m;
        }
        m = (l+r)/2;
    }
    if(!subsequence(text, pat, loc, m)) return (m-1);
    return m;
}

int subsequence(char text[], char pat[], int loc[], int num) {
    int t_len = strlen(text);
    int p_len = strlen(pat);

    int t, p, count, i;

    i=0;

    for(p=0;p<p_len;p++){
        for(count=0;count<num;count++){
            for(t=0;t<t_len && text[t] != pat[p];t++);
            if(t >= t_len) return false;
            else{
                loc[i++] = t;
            }
        }
    }
    return true;    
}

