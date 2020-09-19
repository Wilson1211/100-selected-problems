#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define N 10
#define MIN(a, b) ((a>b)?b:a)

// change stores the minimum banknotes needed for amount money
/**********************************
int chang(int base[], int change[], int amount, int n) {

    int m_amount;
    int min_amount = 100000;
    if(amount == 0) return 0;
    if(change[amount] != 0) return change[amount];
    for(int i=0;i<n;i++) {    
        if(amount == base[i]) {
            return change[amount];
        }
    }

    for(int i=0;i<n&&(amount>=base[i]);i++) {
        m_amount = chang(base, change, amount - base[i], n)+1;
        if(min_amount > m_amount) min_amount = m_amount;
    }
    change[amount] = min_amount;
    return min_amount;
}
***************************************************/

void chang(int base[], int change[], int amount, int n) {
    
    for(int j=2;j<=amount;j++) {
        int banknotes = amount;
        for(int i=0;i<n&&(j>base[i]);i++) {
            banknotes = MIN(banknotes, change[j-base[i]]+1);
        }
        change[j] = banknotes;
    }
}

int main() {
    int n, amount;
    int *base;
    int *money;
    int k;
    int min_paper;

    scanf("%d", &n);
    scanf("%d", &amount);

    base = (int *)malloc(sizeof(int)*n);
    money = (int *)malloc(sizeof(int)*(amount+1));

    memset(money, 0, amount+1);

    for(int i=0;i<n;i++) {
        scanf("%d", &base[i]);
        money[base[i]] = 1;
    }
    //min_paper = chang(base, money, amount, n);
    chang(base, money, amount, n);
    printf("%d\n", money[amount]);

    free(base);
    free(money);
    return 0;
}