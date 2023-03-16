#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 1999999

int main(void){

	int a, b, i, j;
	int data[N];

	srand((unsigned) time(NULL));

	for(i=0;i<N;i++){
		data[i] = i+1;
		//printf("%d ", data[i]);
	}	
	//printf("\n");
    
	for(i=0;i<N;i++){
		a = (int) (rand()/(RAND_MAX+1.0) * N) + 1;
		j = data[a];
		data[a] = data[i];
		data[i] = j;
		if(i!=(N-1)){
			printf("%d ", data[i]);
		}else{
			printf("%d", data[i]);
		}
	}
	
	return 0;
}
