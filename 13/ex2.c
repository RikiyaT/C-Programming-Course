#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define N 3

void PrintAb(double *A,double *b,int n){
  int i,j;
  double *ai=A;
  printf("A,b=\n");
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      printf("%6.1f\t",*(ai+j));
    }
    printf("|%6.1f\n",b[i]);
    ai+=n;
  }
  printf("\n");
}

void swap(double *x,double *y){
  double z;
  z=*x;
  *x=*y;
  *y=z;
  return;
}

int main(void){
  int i,j,k;
  double r;
  double *ai,*ak,*am;
  double *A,*b;

  A=(double*)malloc(N*N*sizeof(double));
  if(A==NULL){
    printf("Cannot allocate memory.\n");
    exit(1);
  }
  b=(double*)malloc(N*sizeof(double));
  if(b==NULL){
    printf("Cannnot allocate memory.\n");
    exit(1);
  }
  printf("Input elements for matrix A\n");
  ai=A;
  for(i=0;i<N;i++){
    for(j=0;j<N;j++){
      printf("A[%d][%d]=",i,j);
      scanf("%lf",ai+j);
    }
    ai+=N;
  }
  printf("Input elements for vector b\n");
  for(i=0;i<N;i++){
    printf("b[%d]=",i);
    scanf("%lf",b+i);
  }

  PrintAb(A,b,N);
  
  ai=A;
  ak=A;
 
  for(k=0;k<N-1;k++){

    int m;
    m=k;
    for(i=k+1;i<N;i++){
      if(fabs(*(ai+i*N+k))>fabs(*(ai+m*N+k))){
	m=i;
      }
    }
    if(m!=k){
      for(j=k;j<N;j++){
	swap(ai+k*N+j,ai+m*N+j);
      }
      swap(&b[k],&b[m]);
    }

    for(i=k+1;i<N;i++){
      r=*(ai+i*N+k) / *(ak+k);
      for(j=k;j<N;j++){
	*(ai+i*N+j)-=*(ak+j) * r;
      }
      b[i]-=b[k] * r;
    }

    PrintAb(A,b,N);
    ak+=N;
  }
  ai=ak;
  for(i=N-1;i>=0;i--){
    for(j=i+1;j<N;j++){
      b[i]-=*(ai+j)*b[j];
    }
    b[i] /= *(ai+i);
    PrintAb(A,b,N);
    ai-=N;
  }

  free(A);
  free(b);

  return 0;
}
