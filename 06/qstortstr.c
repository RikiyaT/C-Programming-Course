#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "compare.h"

int main(void){
  char Data[100];
  printf("Input a string: ");
  scanf("%s", Data);

  int N = strlen(Data);

  qsort((void *)Data, N, sizeof(Data[0]), char_sort);
  printf("%s\n", Data);

  return 0;
}