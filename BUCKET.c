#include <stdio.h>
#include <stdlib.h>

#define   MAXSIZE   1000
#define   LENGTH    4
#define   BUCKET_NO 16
#define   LOOP_COUNT sizeof(int)*8/LENGTH


#define swap(a,b) {int t;t = a;a = b;b = t;}
//#define initnode(x) Node x = {.data=0, .next = NULL}

Node *head;
int mask = 0x0FU;

typedef struct node Node;

struct node{
    int data;
    int x;
    Node *next;
};

struct cell{
    Node *first;
    Node *last;
}basket[BUCKET_NO];

struct Node* listgen(int[], int);
void distribute(void);
void recollect(void);
void putback(int []);


struck Node* listgen(int x[], int n){
    Node *first, *last, *tmp;
    int i;
    
    first = last = (Node*) malloc(sizeof(Node));
    for(i=0;i<n;i++){
        tmp = (Node*) malloc(sizeof(Node));
        tmp.data = input[i];
        tmp.next = NULL;
        last.next = tmp;
        last = tmp;
    }
    return first;
}


void sort(int input[], int n){




}


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
