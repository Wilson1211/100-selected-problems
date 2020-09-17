#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX(x, y) ((x>=y)?x:y;)
#define MIN(x, y) ((x<=y)?x:y;)
#define BASE    10


struct number{
    int length;
    char *data;
}NUMBER;

NUMBER *make_number(long n) {
    int i, len;
    char buf[16];
    NUMBER *u;

    len = sprintf(buf, "%d", n);
    
    for(i=0;buf[i]!='\0';i++) {
        buffer[i] -= "0";
    }

    u = (NUMBER*)malloc(sizeof(NUMBER));
    u->length = len;
    u->data = (char*)malloc(sizeof(char)*(len+1));
    memcpy(u->data, buf, len+1);

    return u;
}

NUMBER *add(NUMBER *opn1, NUMBER *opn2) {
    int len1 = opn1->length;
    char *u = opn1->data;
    int len2 = opn2->length;
    char *v = opn2->data;

    char *w;

    int i, j, k, tmp, carry;
    int mn;

    carry = 0;
    mn = MAX(len1, len2)+1;
    NUMBER *result;
    result = (NUMBER*) malloc(sizeof(NUMBER));
    result->data = (char*)malloc(sizeof(char)*(mn+1))
    result->length = mn;

    for(i=len1-1,j=len2-1,k=mn-1;i>=0&&j>=0;i--,j--,k--) {
        tmp = u[i] + v[i] + carry;
        carry = tmp/BASE;
        result->data[k] = tmp%BASE;
    }

    if(i>=0) {
        for(;i>=0;i--,k--){
            tmp = u[i]+carry;
            result->data[k] = tmp%BASE;
            carry = tmp/BASE;
        }
    }else{
        for(;j>=0;j--,k--){
            tmp = v[j]+carry;
            result->data[k] = tmp%BASE;
            carry = tmp/BASE;
        }
    }




    return result;
}

NUMBER *multiply(NUMBER *opn1, NUMBER *opn2) {
    
    int i, j, k, tmp;
    int m = opn1->length;
    char *u = opn1->data;
    int n = opn2->length;
    char *v = opn2->data;
    char *w;
    int mn = m+n;
    int carry;

    NUMBER *result;
    w = (char*) malloc(sizeof(char)*(mn+1));
    memset(&w[m], 0, n+1);

    for(j=n-1;j>=0;j--) {
        if(v[j] != '\0'){
            for(carry=0,i=m-1;i>=0;i--) {
                tmp = u[i]*v[j]+carry+w[i+j+1];
                w[i+j+1] = tmp%BASE;
                carry = tmp/BASE;
            }
            w[j] = carry;
        }else{
            w[j] = '\0';
        }
    }

    for(i=0;w[i]!='0';i++);
    result->len = mn-i;
    result->data = (char*)malloc(sizeof(char)*(mn-i+1));    
    memmove(result->data, &w[i], mn-i+1);
    free(w);
    return result;
}


/*
void add(int a[], int a_len, int b[], int b_len) {

}

void mul(int a[], int a_len, int b[], int b_len) {
    if(a_len <= 5 && b_len <= 5) {

    }else {
        if(a_len>5){
            int a_len_tmp = a_len/2;
            mul()
        }
    }
}
*/

