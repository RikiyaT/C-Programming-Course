#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(void){
    int a=0, i=1;
    int count=0;
    srand((unsigned) time(NULL));

    for(i=1; i<=10; i++){
        a=(int)(rand()/(RAND_MAX+1.0)*6)+1;
        if(a==3){
            count++;
        }
    
        printf("Dice: %d\n", a);
    }

    printf("3: %d\n", count);
    
    return 0;
}