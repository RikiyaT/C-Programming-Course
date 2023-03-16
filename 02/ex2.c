#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>



int Factorial(int n){
    int fac=1;

    for(int a=1; a<=n; a++){
        fac=fac*a;
    }
    return fac;
}

double mysin(double x){
    double mys=0.0;
    
    for(int n=1; n<=7; n++){
        mys=mys+(pow(-1, n+1)*pow(x, 2*n-1)/Factorial(2*n-1));
    }

    return mys;
}

int main(void){
    double x;
    printf("Input x:");
    scanf("%lf", &x);

    printf("sin(x): %.6f\n", sin(x));
    printf("mysin(x): %.6f\n", mysin(x));

    return 0;
}