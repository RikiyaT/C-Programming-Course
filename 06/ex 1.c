#include <stdio.h>

void PrintData(double *Data, int N){
  int i;
  for (i=0; i<N; i++){
    printf("%.0f,", Data[i]);
  }
  printf("\n");
}

void swap(double *x, double *y){
  double z;
  z = *x;
  *x = *y;
  *y = z;
}

void QuickSortBase(double *Data, int L, int R){
  int l = L, r = R;
  double pivot = Data[(L+R) / 2];
  printf("sorting [%d] ... [%d], pivot = [%d]: %.0f\n", L, R, (L + R) / 2, pivot);

  while (1){
    if (l > r)
      break;
    while (Data[l] < pivot){
      l++;
    }
    while (Data[r] > pivot){
      r--;
    }
    if (l > r)
      break;
    if (l < r){
      printf("swapped [%d]:%.0f <=> [%d]:%.0f\n", l, Data[l], r, Data[r]);
      swap(&Data[l], &Data[r]);
    }
    l++;
    r--;
  }

  if (L > r){
    QuickSortBase(Data, L, l-1);
  }
  if (l < R){
    QuickSortBase(Data, r+1, R);
  }
}

void QuickSort(double *Data, int N){
  if (N >= 2){
    QuickSortBase(Data, 0, N-1);
  }
}

int main(void){
  double Data[] = {1, 3, 4, 3, 5, 5, 2, 4};
  int N = sizeof(Data)/sizeof(Data[0]);

  PrintData(Data, N);
  QuickSort(Data, N);
  PrintData(Data, N);

  return 0;
}