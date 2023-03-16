#include <stdio.h>

int main(void){
    int a, n;
    int x=1;

    printf("Input a: ");
    scanf("%d", &a);
    printf("Input n:");
    scanf("%d", &n);
    if(a==0){
        x=0;
    }else if(n==0){
        x=1;
    }else{
        for(int i=1; i<=n; i++){
            x=x*a;
        }
    }

    printf("%d^%d=%d\n", a, n, x);

    return 0;
}