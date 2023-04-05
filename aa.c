#include<stdio.h>
#include <synchapi.h>
#include<string.h>
#include <assert.h>
#include <math.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define MAXSIZE 100

typedef int ElemType;
typedef int Status;

typedef struct{
    ElemType * base;
    ElemType * top;
    int stacksize;
}SqStack;

Status InitStack(SqStack* S){
    S -> base = (SqStack*)malloc(sizeof(ElemType) * MAXSIZE);
    if(!(S -> base)){
        exit(OVERFLOW);
    }
    S -> top = S -> base;
    int stacksize = 0;
    return OK;
}

Status EnStack(SqStack* S,int n,ElemType e){
    for(int i = 0;i < n;i++){
        if(S -> top - S -> base != MAXSIZE){
            *(S -> top++) = e;
        }
    }
}

Status GetTop(SqStack S){
    if(S.top - S.base != 0){
        printf("%d",*(--(S.top)));
    }
}

int main(){

    int Number = 0;
    printf("请输入想要转换的数字:\n");
    scanf("%d",&Number);

    SqStack S;
    InitStack(&S);

    while(Number){
        if(Number > 0){
            int remainder = Number % 2;
            Number /= 2;
            EnStack(&S,1,remainder);
        }
    }

    while(S.top - S.base != 0){
        GetTop(S);
        S.top--;
    }
}