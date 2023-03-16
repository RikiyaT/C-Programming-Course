#include<stdio.h>

int powfor(int a, int n){
    if(a==0){
        return 0;
    }else if(n==0){
        return 1;
    }else{
        return a*powfor(a, n-1);
    }
}

int main(void){
    int A, N;
    printf("Input a: ");
    scanf("%d", &A);
    printf("Input n:");
    scanf("%d", &N);
    powfor(A, N);
    printf("%d^%d=%d\n", A, N, powfor(A, N));

    return 0;
}