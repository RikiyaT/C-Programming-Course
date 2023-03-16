#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int char_sort(const void *a, const void *b){
  return strcmp(a, b);
}

int main(void){
  char Data[100];
  printf("Input a string: ");
  scanf("%s", Data);

  int N = strlen(Data);

  qsort((void *)Data, N, sizeof(Data[0]), char_sort);
  printf("%s\n", Data);

  return 0;
}