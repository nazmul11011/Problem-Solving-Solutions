#include<stdio.h>
#include <math.h>
int main( ) {

    int x;
    while(scanf("%d", &x)==1) {
        if(x==42) {
            return 0;
        }
        printf("%d\n", x);
    }

    return 0;
}