#include <stdio.h>
#include <math.h>

int pascal(int i, int j){
  if (j == 0 || i == j){
    return 1;
  }
  else{
    return pascal(i-1, j-1) + pascal(i-1,j);
  }
}

int main(void){
  int i, j, N;
  printf("N: ");
  scanf("%d", &N);

  N = pow(2, N);

  for (i = 0; i<N; i++){
    for (j = 0; j<=i; j++){
      putchar(pascal(i, j) % 2 ? '*' : ' ');
    }
    putchar('\n');
  }
  return 0;
}