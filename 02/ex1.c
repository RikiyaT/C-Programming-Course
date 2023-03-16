#include <stdio.h>

#define row 3
#define col 4

int main(void){
 int A[row][col];
 int b[col];
 int i;
 int j;
 int num;

 i = -1;
 while (++i < row)
 {
  j = -1;
  while (++j < col)
   A[i][j] = (i * 4) + j + 1;
 }
 i = 0;
 while (i < col)
 {
  i ++;
  b[i - 1] = i * 4;
 }
 printf("A=\n");
 for (i = 0; i < row; i++){
  for (j = 0; j < col; j++){
   printf("%3d", A[i][j]);
  }
  printf("\n");
 }
 printf("b=\n");
 i = -1;
 while (++i < col)
  printf("%2d\n", b[i]);
 printf("A*b=\n");
 i = -1;
 while (++i < row)
 {
  j = -1;
  num = 0;
  while (++j < col)
   num += A[i][j] * b[j];
  printf("%3d\n", num);
 }
 return 0;
}