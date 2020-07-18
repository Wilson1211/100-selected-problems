#include <stdio.h>
#include <stdlib.h>

#define   MAXSIZE   1000

#define swap(a,b) {int t;t = a;a = b;b = t;}
#define initnode(x) Node x = {->data=0, ->next = NULL}


typedef struct node *Node;

struct node{
    int data;
    Node next;
};

void sort(int x[], int n){
    Node a[40], head, end, tmp;
    int i, j;
    int l = 10, r = 1;
    for(i=0;i<n;i++){
        Node y = malloc(sizeof(struct node));
        j = x[i]%l;
        j = x[i]/r;
        y->data = x[i];
        if(a[j]->next == NULL){
            a[j]->next = y;
        }else{
            tmp = a[j]->next;
            while(tmp->next != NULL) {tmp = tmp->next;}
            tmp->next = y;
        }
    }

    // find head
    i=0;
    while(a[i]->next == NULL) i++;
    head->next = a[i]->next;
    tmp = head->next;

    for(i=0;i<n;i++){
        tmp->next = a[i]->next;
        while(tmp->next != NULL) tmp = tmp->next;        
    }

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

