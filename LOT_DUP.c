#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define   MAXSIZE   1000
//#define ln(x) log(x)/log(2)

#define swap(a,b) {int t;t = a;a = b;b = t;}

int dup;


void sort(int input[], int n){
    int i, index;
    i=1;
    while(i<n){
        if(x[i-1] == x[i]) {
            dup = x[i];
            break;
        }
    }

    



}


/*   deal with situations when element not equal to dup happens more than one time
void sort(int input[], int n){
    int i=0, index=0;

    
    while(count < ln(n)){
        if(input[i-1] == input[i]) count++;
        else count = 0;
    }
    dup = input[i];

    i = n-1;
    while(index<i){
        while(input[index] != dup) index++;
        while(input[i] == dup) i--;
        if(index > i) break;
        swap(input[index], input[i]);
    }
    

    // index is the last element not equal dup
    index = i;
    //mergesort(input, index)
    count = n-1;
    for(i=index;i>=0;i--){
        if(input[i] != dup) swap(input[i], input[count--]);
    }
}
*/

void main(void)
{
     int  input[MAXSIZE+1];
     int  n, i;
     char line[100];

     printf("\nSort Program Testing Driver for Random Data");
     printf("\n===========================================");
     printf("\n\nHow many data items ( <= 1000) ? ");
     gets(line);
     n = atoi(line);

     srand((unsigned) clock());
     printf("\nGenerated Data :");
     for (i = 0; i < n; i++) {
          if (i % 10 == 0)  printf("\n");
          input[i] = rand()%4000;
          printf("%6d", input[i]);
     }

     sort(input, n);
     printf("\n\nSorted Data :");
     for (i = 0; i < n; i++) {
          if (i % 10 == 0)  printf("\n");
          printf("%6d", input[i]);
     }
}



/*
void initNodeArray(Node a[], int n){
    int i;
    for(i=0;i<n;i++){
        a[i].data = 0;
        a[i].next = NULL;
    }
}

void find_max(int x[], int n, int *max, int *length){
    int i, tmp;
    *length = 0;
    *max = x[0];
    for(i=1;i<n;i++){
        *max = (*max>x[i])?*max;x[i];
    }
    tmp = *max;
    while(tmp > 0){
        *length++;
        tmp/=10;
    }
}

void sort(int x[], int n){
    Node a[40], head, end, tmp;
    int max, length; // for length of number
    int i, j, count;
    int l = 10, r = 1;
    find_max(x, n, max, length);
    initNodeArray(a);
    while(length){
        for(i=0;i<n;i++){
            //Node y = malloc(sizeof(struct node));
            initnode(y);
            j = x[i]%l;
            j = j/r;
            y.data = x[i];
            if(a[j].next == NULL){
                a[j].next = &y;
            }else{
                tmp = *(a[j].next);
                count = 0;
                while(tmp.next != NULL) {tmp = *(tmp.next);count++;}
                tmp.next = &y;
            }
        }

        // find head
        i=0;
        while(a[i].next == NULL) i++;
        head.next = a[i].next;
        tmp = *(head.next);

        for(i=0;i<n;i++){
            tmp.next = a[i].next;
            while(tmp.next != NULL) tmp = *(tmp.next);        
        }
        length--;
    }
}
*/
