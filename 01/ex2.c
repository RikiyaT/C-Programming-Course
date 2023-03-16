#include<stdio.h>

int main(void){
    double a=0.0, b=0.0, c=0.0, sum=0.0, avg=0.0;

    printf("Please input three values (double)\n");
    printf("a: ");
    scanf("%lf", &a);
    printf("b: ");
    scanf("%lf", &b);
    printf("c: ");
    scanf("%lf", &c);
    sum=a+b+c;
    avg=sum/3;
    printf("Sum: %.1f, Average: %.2f\n", sum, avg);

    return 0;
}