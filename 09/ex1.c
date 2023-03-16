#include<stdio.h>
#include<stdlib.h>

void *mallocx(int size){
  void *p=malloc(size);
  if(p==NULL){
    printf("cannnot allocate memory\n");
    exit(1);
  }
  return p;
}

typedef struct{
  double *Data;
  int Size;
  int Count;
}Stack;

Stack *CreateStack(int size){
  Stack *s=(Stack*)malloc(sizeof(Stack));
  s->Data=(double*)malloc(sizeof(double)*size);
  s->Size=size;
  return s;
}

void PrintStack(Stack *s){
  int i;
  printf("stack: ");
  if(s->Count==0){
    printf("(none)");
  }else{
    for(i=0;i<s->Count;i++){
      printf("%.1lf,",s->Data[i]);
    }
  }
  printf("\n");
}

void PushStack(Stack *s, double x){
  if(s->Count==s->Size){
    printf("stack overflow\n");
    exit(1);
  }else{
    s->Data[s->Count]=x;
    s->Count++;
  }
}

double PopStack(Stack *s){
  if(s->Count==0){
    printf("stack underflow\n");
    exit(1);
  }else{
    s->Count--;
    return s->Data[s->Count];
  }
}

void DisposeStack(Stack *s){
  free(s->Data);
  free(s);
}

int main(void){

  Stack *s=CreateStack(4);


  while(1){
    
    PrintStack(s);
    
    int select;
    printf("select (1)Push, (2)Pop, (0)Exit:");
    scanf("%d",&select);
   
    if(select==0){
      exit(1);
    }
    
    if(select==1){
      double x;
      printf("input: ");         
      scanf("%lf",&x);
      PushStack(s,x);     
    }
    
    if(select==2){
      double y;
      y=PopStack(s);      
      printf("output: %lf\n",y); 
    }

  }

  DisposeStack(s);
  return 0;
}
