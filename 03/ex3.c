#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(void){
    double x=0., y=0.;
    double v=0., theta=0., t=0.;

    printf("Initial velocity (m/s)(double): ");
    scanf("%lf", &v);
    printf("Angular (0-360 degree)(double): ");
    scanf("%lf", &theta);

    while(1){
        x=v*cos(2*M_PI*theta/360)*t;
        y=v*sin(2*M_PI*theta/360)*t-(0.5*9.8*t*t);

        if(y<0){
            break;
        }
    t+=0.1;
    }

    printf("t: %.2f, x: %.2f, y: %.2f\n", t, x, y);

    return 0;

}