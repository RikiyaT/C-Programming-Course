#include<stdio.h>
#include<string.h>

struct student{
    char name[10];
    int math, physics, english;
    double avg;
};

struct student Average(struct student a){
    a.avg=((double)a.math+(double)a.physics+(double)a.english)/3;

    return a;
};

int main(void){
    struct student s1;

    printf("Please input name: ");
    scanf("%s", s1.name);
    printf("Please input math score: ");
    scanf("%d", &s1.math);
    printf("Please input physics score: ");
    scanf("%d", &s1.physics);
    printf("Please input English score: ");
    scanf("%d", &s1.english);

    s1=Average(s1);

    printf("Name: %s, Math: %d, Physics: %d, English: %d, Average: %.6f\n", s1.name, s1.math, s1.physics, s1.english, s1.avg);

    return 0;

}