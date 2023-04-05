#include<stdio.h>
#include <synchapi.h>
#include<string.h>
#include <assert.h>
#include <math.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define MAXSIZE 100

typedef char ElemType;
typedef int Status;

typedef struct{
    ElemType * base;
    ElemType * top;
    int stacksize;
}SqStack;

Status InitStack(SqStack* S){
    S -> base = (SqStack *)malloc(sizeof(ElemType) * MAXSIZE);
    if(!(S -> base)){
        exit(OVERFLOW);
    }
    S -> top = S -> base;
    S -> stacksize = MAXSIZE;
}

Status Push(SqStack* S,ElemType e){
    if(S -> top - S -> base == MAXSIZE){
        exit(OVERFLOW);
    }
    *(S -> top++) = e;
    return OK;
}

Status Pop(SqStack* S){
    if(S -> top == S -> base){
        printf("Õ»¿Õ");
        exit(OVERFLOW);
    }
    (S -> top)--;
    return OK;
}

ElemType GetTop(SqStack S){
    if(S.top == S.base){
        printf("Õ»¿Õ");
        return ERROR;
    }
    ElemType e = ' ';
    return e = *(--(S.top));
}

Status Is_Empty(SqStack* S){
    if(S -> top == S -> base){
        return OK;
    }
    return ERROR;
}

Status Match(SqStack* S,int length,char* A){
    int flag = 1;
    for(int i = 0;i < length;i++){
        if((A[i] == '(') || (A[i] =='[') || (A[i] =='{')){
            Push(S,A[i]);
            continue;
        }else if(A[i] == ')'){
            if(!Is_Empty(S) && GetTop(*S) == '('){
                Pop(&S);
                continue;
            }else{
                flag = 0;
                continue;
            }
        }else if(A[i] == ']'){
            if(!Is_Empty(S) && GetTop(*S) == '['){
                Pop(S);
                continue;
            }else{
                flag = 0;
                continue;
            }
        }else if(A[i] == '}'){
            if(!Is_Empty(S) && GetTop(*S) == '{'){
                Pop(S);
                continue;
            }else{
                flag = 0;
                continue;
            }
        }
    }
    if(flag && Is_Empty(S)){
        printf("Æ¥Åä³É¹¦");
        return OK;
    }else{
        printf("Æ¥ÅäÊ§°Ü");
        return ERROR;
    }
}

int main(){
    char Parentheses[10] = {'(','[',']',')'};
    int length = strlen(Parentheses);
    SqStack S;
    InitStack(&S);

    Match(&S,length,Parentheses);
}
