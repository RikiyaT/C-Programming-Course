#include<stdio.h>
#include<stdlib.h>

void PrintMatrix(double *A, int n){
  int i,j;
  double *ai=A;
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      printf("%6.1f",*(ai+j));
    }
    ai+=n;
    printf("\n");
  }
}

void Mult_MV(double *A, double *B, int N){
  int i,j,k;
  double *AB,*ai,*bk,*abi;
  ai=A;
  bk=B;
  AB=(double*)malloc(N*N*sizeof(double));
  abi=AB;
  for(i=0;i<N;i++){
    for(j=0;j<N;j++){
      *(abi+j)+=0.0;
      bk=B;
      for(k=0;k<N;k++){
	*(abi+j)+=*(ai+k) * (*(bk+j));
	bk+=N;
      }
      printf("%6.1f",*(abi+j));
    }
    ai+=N;
    abi+=N;
    printf("\n");
  }
}

int main(void){
  int i,j,k;  
  double *B, *A;

  int N;
  printf("N=");
  scanf("%d",&N);
  A=malloc(N*sizeof(double*));
  for(i=0;i<N;i++){
    A=malloc(N*N*sizeof(double));
  }
  if(A==NULL){
    printf("Cannot allocate memory.\n");
    exit(1);
  }
  double *ai;
  ai=A;
  for(i=0;i<N;i++){
    for(j=0;j<N;j++){
      printf("A[%d][%d]=",i,j);
      scanf("%lf",ai+j);
    }
    ai+=N;
  }
  B=malloc(N*sizeof(double*));
  for(i=0;i<N;i++){
    B=malloc(N*N*sizeof(double));
  }
  if(B==NULL){
    printf("Cannnot allocate memory.\n");
    exit(1);
  }
  double *bi;
  bi=B;
  for(i=0;i<N;i++){
    for(j=0;j<N;j++){
      printf("B[%d][%d]=",i,j);
      scanf("%lf",bi+j);
    }
    bi+=N;
  }
  printf("A=\n");
  PrintMatrix(A,N);
  printf("B=\n");
  PrintMatrix(B,N);
  printf("AB=\n");
  Mult_MV(A,B,N);
  free(A);
  free(B);
  
  return 0;
}
