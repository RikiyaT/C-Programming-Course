#include <stdio.h>
#include <math.h>

int main(void){
  int i, j, N;
  printf("N: ");
  scanf("%d", &N);

  N = pow(2, N);

  int x[N][N];

  for (i = 0; i < N; i++){
    for (j = 0; j <= i; j++){
      if (j == 0 || i == j){
        x[i][j] = 1;
      }
      else
      {
        x[i][j]= x[i-1][j-1]+ x[i-1][j];
      }
    }
  }

  for (i = 0; i < N; i++){
    for (j = 0; j <= i; j++){
      putchar(x[i][j] % 2 == 1 ? '*' : ' ');
    }
    putchar('\n');
  }
  return 0;
}