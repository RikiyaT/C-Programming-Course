#include <stdio.h>

int combination(int n, int r){
    if(r==0||r==n){
        return 1;
    }else if(r==1){
        return n;
    }else{
        return combination(n-1, r-1)+combination(n-1, r);
    }
}

int main(void){
    int N, R;
    printf("Input n : ");
    scanf("%d", &N);
    printf("Input r : ");
    scanf("%d", &R);
    combination(N, R);
    printf("%d C %d = %d\n", N, R, combination(N,R));

    return 0;
}