#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX_SIZE 100

void display(int dist[][MAX_SIZE]) {

}

void readin(int dist[][MAX_SIZE], int *number) {

    int origin, dest, length, n;

    FILE *fp;
    char line[100];    
    fp = fopen("SHORTEST_IN1.txt", "r");

    fgets(line, 100, fp);
    sscanf(line, "%d", &n);
    *number = n;

    fgets(line, 100, fp);
    sscanf(line, "%d%d%d", &origin, &dest, &length);
    while(origin != 0 && dest != 0 && length != 0){        
        dist[origin-1][dest-1] = length;
        fgets(line, 100, fp);
        sscanf(line, "%d%d%d", &origin, &dest, &length);
    }
}

floyd(int dest[][MAX_SIZE], int number, int P[][MAX_SIZE]) {
    int i, j, k;
    for(int k = 0;k<number;k++) {
        for(int j=0;j<number;j++) {
            for(int i=0;i<number;i++) {
                if(dest[i][k]+dest[k][j] < dest[i][j]) {
                    P[i][j] = P[k][j];
                    dest[i][j] = dest[i][k]+dest[k][j];
                }
            }
        }
    }
}

int main() {

    int i, j, k;

    int dest[MAX_SIZE][MAX_SIZE];
    int number;

    readin(dest, &number);
    
    display(dest);
    return 0;
}