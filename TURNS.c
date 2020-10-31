#include <stdio.h>
#include <stdlib.h>

struct node{
    int x;
    int y;
    bool on_axis;   // origin = 0, 1,2,3,4
    int dim;    // 
}Node;

void check_dim(Node *nod) {
    int mul = (nod->x)*(nod->y);
    if(mul == 0) {
        nod->on_axis = 1;
        if(nod->x == 0) {
            if(nod->y == 0) {
                nod->dim = 0;
            }else if(nod->y > 0) {
                nod->dim = 2;
            }else {
                nod->dim = 4;
            }
        }else {
            if(nod->x > 0) {
                nod->dim = 1;
            }else {
                nod->dim = 3;
            }
        }
    }else {
        nod->on_axis = 0;
        if(mul > 0) {
            if(nod->x > 0) {
                nod->dim = 1;
            }else {
                nod->dim = 3;
            }
        }else {
            if(nod->x > 0) {
                nod->dim = 4;
            }else {
                nod->dim = 2;
            }
        }
    }
}


int main() {
    Node *nod_arr;
    int N = 4;
    nod_arr = (Node *)malloc(sizeof(Node)*N);

    for(int i=0;i<N;i++) {
        scanf("%d %d", nod_arr[i].x, nod_arr[i].y);
        check_dim(nod_arr[i]);
    }


    return 0;
}