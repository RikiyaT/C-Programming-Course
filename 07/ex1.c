#include<stdio.h>
#include<string.h>

struct student{
    char name[20];
    int math;
    int phys;
};

int main(void){
     struct student a;
      strcpy(a.name,"Frank");
      a.math = 90;
      a.phys = 83;

      printf("Name: %s\n", a.name);
      printf("Math: %d\n", a.math);
      printf("Physics: %d\n", a.phys);
}
