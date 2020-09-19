#include <stdio.h>
#include <stdlib.h>

#define MAXLENGTH   100
#define EOF         '\0'
#define LEFT_PAR    '\1'
#define RIGHT_PAR   '\2'
#define PLUS_MINUS   '\3'
#define MUL_DIV     '\4'

int stack[MAXLENGTH];
/*
int symb_to_num(char a){
    if(a == '\0') return 1;
    else if(a == '(') return 2;
    else if(a == ')') return 3;
    else if(a == '+' || a == '-') return 4;
    else if(a == '*' || a == '/') return 5;
    else return 0;
}
*/

void initial(void);         // initial stack
char stack_top(void);       // return top of stack
void push(char, char);      // push symbol to stack
char pop(void);             // pop stack


int main(void){
    char line[1000];
    char *p;
    char opr, t;

    p = gets(line);

    initial();
    for(;;p++){

    }







}

int stack_ptr;
int code[MAXLENGTH];


void initial(void){
    stack_ptr = 0;
    stack[0] = '\0';
}

char stack_top(void){
    return code[top];
}









