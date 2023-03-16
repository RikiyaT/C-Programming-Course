#include<stdio.h>

int main(void){
    int a;
    printf("Please input your score (integer): ");
    scanf("%d", &a);
    printf("Your score: %d, ", a);
    if(a<60){
        printf("Grade: F\n");
    }else if(a<70){
        printf("Grade: C\n");
    }else if(a<80){
        printf("Grade: B\n");
    }else if(a<90){
        printf("Grade: A\n");
    }else if(a<=100){
        printf("Grade: A+\n");
    }else{
        printf("Error\n");
    }

    return 0;
}