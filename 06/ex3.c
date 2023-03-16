#include <stdio.h>

void PrintData(double *Data, int N){
  int a;
  for (a=0; a<N; a++){
    printf("%.0f,", Data[a]);
  }
  printf("\n");
}

void swap(double *x, double *y){
  double z;
  z = *x;
  *x = *y;
  *y = z;
}

void BubbleSort(double *Data, int N){
  int i, j;
  for (j=N; j>=2; j--){
    for (i=0; i<j-1; i++){
      if (Data[i]>Data[i + 1]){
        swap(&Data[i], &Data[i + 1]);
      }
      PrintData(Data, N);
    }
  }
}

int main(void){
  double Data[] = {5, 3, 1, 4, 2};
  int N = sizeof(Data)/sizeof(Data[0]);
  PrintData(Data, N);
  BubbleSort(Data, N);
  return 0;
}