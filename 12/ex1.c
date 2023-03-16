#include<stdio.h>
#include<stdlib.h>

void PrintMatrix(double **A, int n){
  int i,j;
  double *ai=A[0];
  printf("A=\n");
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      printf("%6.1f",*(ai+j));
    }
    ai+=n;
    printf("\n");
  }
}

void PrintVector(double *x, int n){
  int i;
  printf("x=\n");
  for(i=0;i<n;i++){
    printf("%6.1f\n",x[i]);
  }
}

void Mult_MV(double **A, double *x, int N){
  double y[N];
  double *ai=A[0];
  int i,j;
  for(i=0;i<N;i++){
    *(y+i)=0;
    for(j=0;j<N;j++){
      *(y+i) += *(ai+j) * (*(x+j));
    }
    ai+=N;
  }

  printf("Ax=\n");
  for(i=0;i<N;i++){
    printf("%6.1f\n",*(y+i));
  }
}

int main(void){
  int i,j;  
  double *x, **A;

  int N;
  printf("N=");
  scanf("%d",&N);
  A=malloc(N*sizeof(double*));
  for(i=0;i<N;i++){
    A[i]=malloc(N*sizeof(double));
  }
  if(A==NULL){
    printf("Cannot allocate memory.\n");
    exit(1);
  }
  double *ai;
  ai=A[0];
  for(i=0;i<N;i++){
    for(j=0;j<N;j++){
      printf("A[%d][%d]=",i,j);
      scanf("%lf",ai+j);
    }
    ai+=N;
  }
  x=malloc(N*sizeof(double));
  if(x==NULL){
    printf("Cannot allocate memory.\n");
    exit(1);
  }
  for(i=0;i<N;i++){
    printf("x[%d]=",i);
    scanf("%lf",x+i);
  }
  PrintMatrix(A,N);
  PrintVector(x,N);
  Mult_MV(A,x,N);
  free(A);
  free(x);
  
  return 0;
}
