#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<sys/time.h>

double func(double x){
  double y;
  y=cos(x*x)+atan(x-erf(x)-asinh(x*x*x));
  return y;
}

double Newton(double (*func_p)(double),double init, double eps, int imax){

  int i;
  double x_old=init;  
  double x_new;       
 
  for(i=0;i<imax;i++){
    double h=1e-6;
    double f=func_p(x_old);
    double df=(func_p(x_old+h)-func_p(x_old))/h;
    x_new=x_old-f/df;  
    
    if(fabs(x_new-x_old)<eps){
      return x_new;
    }
    x_old=x_new;
  }

  return 0/.0;
}

int main(void){
  double x;
  int i;
  for(i=-3;i<=3;i++){
    x=Newton(func,i,1e-6,100);
    if(-3<=x && x<=3){
      printf("The root is: %+.8f\n",x);
      break;
    }
  }
  
  return 0;
}
