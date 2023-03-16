#include<stdio.h>

int main(void){
    double height=0.0, weight=0.0, bmi=0.0;
    printf("Please input your height (cm): ");
    scanf("%lf", &height);
    printf("Please input your weight (kg): ");
    scanf("%lf", &weight);
    bmi=10000*weight/(height*height);
    printf("Your BMI is %.1f. ", bmi);
    if(bmi<18.5){
        printf("Underweight\n");
    }else if(bmi<25.0){
        printf("Normal\n");
    }else if(bmi<30.0){
        printf("Pre-obese\n");
    }else{
        printf("Obese class\n");
    }

    return 0;
}