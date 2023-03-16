#include<stdio.h>

void Hanoi(int n, char *from, char *work, char *dest){
    if(n>=2){
        Hanoi(n-1, from, dest, work);
    }
    printf("Move a disk from %s to %s\n", from, dest);
    if(n>=2){
        Hanoi(n-1, work, from, dest);
    }
}

int main(void){
    int N;
    printf("How many disks? ");
    scanf("%d", &N);
    Hanoi(N, "A", "B", "C");
    return 0;
}