#include<stdio.h>
#include <math.h>
int main( ) {

    double x;
    scanf("%lf", &x);
    
    x=ceil(x/5);
    
    int y=x;
    
    printf("%d", y);

    return 0;
}