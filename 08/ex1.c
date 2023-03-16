#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

double getTimeOfDay_sec(){
    struct timeval tv;
    gettimeofday(&tv,NULL);

    return tv.tv_sec + tv.tv_usec * 1e-6;
}

int* ReadDataFile(const char *FileName, int *N){
	int i;
	FILE *file;
	int *Data;

	file=fopen(FileName,"r");
	if (file == NULL){
		fprintf(stderr, "cannot open file: %s\n", FileName);
		exit(1);
	}

	for (i=0;;i++){
		double dummy;
		if (fscanf(file, "%lf",&dummy) != 1){
			break;
		}
	}
	*N = i;
	printf("data size is %d\n",i);
	Data = (int*)malloc(sizeof(int)*i);
	if (Data==NULL){
		fprintf(stderr, "cannot allocate memory \n");
		exit(1);
	}
	rewind(file);
	for (i=0;i<*N;i++){
		fscanf(file, "%d",&Data[i]);
	}
	fclose(file);
	return Data;
}

int BinarySearch(int *Data, int N, int key){
    int l1=0,l2=N,m;
    while (l1<l2){
        m=(l1+l2)/2;
        if (Data[m] < key){
            l1 = m+1;
        }else{
            l2 = m;
        }
    }
    if (Data[l1] == key){
        printf("found. index: %d\n", l1);
        return 0;
    }
    printf("not found\n");
    return -1;
}

int FullSearch(int *Data, int N, int key){
    for (int i=0;i<N;i++){
        if (Data[i] == key){
            printf("found. index: %d\n", i);
            return 0;
        }
    }
    printf("not found\n");
    return -1;
}

int cmp(const void *n1, const void *n2){
		return *(int *)n1 > *(int *)n2;
}

int main(){
    int N, i1, i2, key;
    double t1_full,t2_full,t1_binary,t2_binary;
    int *Data;

    Data = ReadDataFile("student.txt", &N);
    printf("key: ");
    scanf("%d",&key);

    qsort(Data,N,sizeof(int),cmp);
    printf("(Binary)"); 
    t1_binary = getTimeOfDay_sec();
    i1 = BinarySearch(Data, N, key);
    t2_binary = getTimeOfDay_sec();
    printf("BinarySearch: %f (sec)\n",t2_binary-t1_binary);

    printf("(Full)");
    t1_full = getTimeOfDay_sec();
    i1 = FullSearch(Data, N, key);
    t2_full = getTimeOfDay_sec();

    printf("FullSearch: %f (sec)\n",t2_full-t1_full);
    return 0;
}
