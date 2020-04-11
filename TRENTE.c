#include <stdio.h>
#include <stdlib.h>



void trente(){
    int i, n, g, q, v, e, c;
    int num1, num2, tmp;
    for(i = 1; i <= 9; i++){
        for(n = 1; n <= 9; n++){
            for(g = 1; g <= 9; g++){
                for(c = 1; c <= 9; c++){
                    for(q = 1; q <= 9, q != 5;q++){
                        for(v = 8; v <= 9; v++){
                            for(e = 3; e <= 9; e += 2){
                                num1 = v*10000+i*1000+n*100+g*10+1;
                                num2 = c*1000+i*100+n*10+q;
                                tmp = 100010+e*1000+n*100+e;
                                if(tmp == num1+num2*2) printf("%d", tmp)
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}