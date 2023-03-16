#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct student{
    int No;
    int Math;
    int Phy;
};

void printStudent(struct student *stu){
    printf("No: ");
    for (int i=0;i<20;i++){
        printf("%3d",stu[i].No);
    }
    printf("\n");
    printf("Math: ");
    for (int i=0;i<20;i++){
        printf("%3d",stu[i].Math);
    }
    printf("\n");
    printf("Phy: ");
    for (int i=0;i<20;i++){
        printf("%3d",stu[i].Phy);
    }
    printf("\n");
    printf("\n");
}

int cmpMath(const void *st1, const void *st2){
    return ((struct student *)st1)->Math > ((struct student *)st2)->Math;
}

int cmpPhy(const void *st1, const void *st2){
    return ((struct student *)st1)->Phy > ((struct student *)st2)->Phy;
}

int main(void){
    srand((unsigned int)time(NULL));
    struct student stu[20];
    for (int i=0;i<20;i++){
        stu[i].No = i+1;
        stu[i].Math = rand() % 101;
        stu[i].Phy = rand() % 101;
    }

    printf("Before sorting\n");
    printStudent(stu);
    qsort(stu,20,sizeof(struct student), cmpMath);
    printf("After sorting for Math\n");
    printStudent(stu);
    qsort(stu,20,sizeof(struct student), cmpPhy);
    printf("After sorting for Phy\n");
    printStudent(stu);
    return 0;
}
