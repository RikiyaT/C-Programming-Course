#include <stdio.h>
#include <string.h>

int main(void){
    FILE *out;
    int a, i, j;
    out=fopen("kuku", "w");

    for(i=1; i<=9; i++){
        for(j=1; j<=9; j++){
            a=i*j;
            fprintf(out, "%2d\t", a);
        }
        fprintf(out, "\n");
    }
    
    fclose(out);
}