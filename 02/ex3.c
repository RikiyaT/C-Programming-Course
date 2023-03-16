#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int Factorial(int n){
    int fac = 1;

    for(int a = 1; a <= n; a++){
        fac = fac * a;
    }
    return fac;
}

double mysin(double x){
    double mys = 0.0;
    
    for(int n = 1; n <= 7; n++){
        mys = mys + (pow(-1, n + 1) * pow(x, (2 * n) - 1) / Factorial((2 * n) - 1));
    }

    return mys;
}

int main(void)
    {
    int  i;
    double r;
    double error;
    double x;
    double y;
    int  max_num;
    
    r = 0;
    printf("How many trials?");
    scanf("%d", &max_num);
    srand((unsigned)time(NULL));
    for (i = 0; i < max_num; i++){
        x = (double)rand() / RAND_MAX;
        y = (double)rand() / RAND_MAX;
        if (y < mysin(x * M_PI))
        r++;
    }
    r /= (double)max_num;
    error = (2 / M_PI) - r;
    printf("Result is %f (Error: %f)\n", r, error);
    return 0;
}