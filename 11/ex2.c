#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<sys/time.h>

double func(double x){
  double y;
  y=cos(x*x)+atan(x-erf(x)-asinh(x*x*x));
  return y;
}

double func_d(double x){
  double y;
  double h=1e-6;
  y=(func(x+h)-func(x))/h;
  return y;
}

double Newton(double (*func_p)(double), double init, double eps, int imax){


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
  double x[100];
  double i=-3.0;
  int j=0;
  int k;

  while(i<=3.0){
    double y=Newton(func_d,i,1e-6,100);
    if(-3<=y && y<=3){
      x[j]=y;
      j++;
    }
    i=i+0.5;
  }

  double x_no0[j];
  for(k=0;k<j;k++){
    x_no0[k]=x[k];
  }

  int p,g;
  double tmp;
  for(p=0;p<j;++p){
    for(g=p+1;g<j;++g){
      if(x_no0[p]>x_no0[g]){
	tmp=x_no0[p];
	x_no0[p]=x_no0[g];
	x_no0[g]=tmp;
      }
    }
  }
 
  for(k=0;k<j;k++){
    if(fabs(x_no0[k]-x_no0[k-1])>1e-6){
      printf("Extrema: %+.8f\n",x_no0[k]);
    }
  }
 
  return 0;
}
