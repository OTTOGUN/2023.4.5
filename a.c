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

typedef struct LNode{
    ElemType index;
    float coefficient;
    struct LNode* next;
}LNode,*LinkList;

Status InitLinkList(LNode* L){
    L -> coefficient = 0;
    L -> index = 0;
    L -> next = NULL;;
}

Status EnList(LNode* L,int n){
    LNode* r = L;
    ElemType e1 = 0;
    ElemType e2 = 0;
    for(int i = 0;i < n;i++){
        LNode* p = (LinkList)malloc(sizeof(LNode));
        printf("请分别输入第%d项的系数与指数:\n",i + 1);
        scanf("%d %d",&e1,&e2);
        p -> index = e2;
        p -> coefficient = e1;
        p -> next = NULL;
        r -> next = p;
        r = p;
    }
}

Status PrintList(LNode* L){
    LinkList p = L -> next;
    while (p){
        if(p -> coefficient > 0) {
            printf("%.1fX^%d", p-> coefficient, p ->index);
        }
        if(p -> coefficient < 0){
            printf("(%.1fX^%d)", p -> coefficient, p ->index);
        }
        if(p -> next != NULL){
            printf(" + ");
        }
        p = p -> next;
    }
}

Status AddList(LNode* LA,LNode* LB){
    LinkList la = LA -> next;
    LinkList lb = LB -> next;
    LinkList lc = LA;
    while(la && lb){
        LinkList p = (LinkList)malloc(sizeof(LNode));
        if(la -> index == lb -> index){
            if(la -> coefficient + lb -> coefficient == 0){
                la = la -> next;
                lb = lb -> next;
            }
            p -> coefficient = la -> coefficient + lb -> coefficient;
            p -> next = NULL;
            p -> index = la -> index;
            la = la -> next;
            lb = lb -> next;
            lc -> next = p;
            lc = p;
        }
        else if(la -> index > lb -> index){
            p -> index = lb -> index;
            p -> coefficient = lb -> coefficient;
            lb = lb -> next;
            lc -> next = p;
            lc = p;
        }
        else if(la -> index < lb -> index){
            p -> index = la -> index;
            p -> coefficient = la -> coefficient;
            la = la -> next;
            lc -> next = p;
            lc = p;
        }
    }
    if(la || lb){
        lc -> next = la?la:lb;
    }
    return OK;
}

int main(){
    LNode LA;
    LNode LB;

    InitLinkList(&LA);
    InitLinkList(&LB);

    int a,b;
    printf("请输入想要建立的多项式项数：");
    scanf("%d",&a);
    EnList(&LA,a);
    printf("############分割线############\n");
    printf("请输入想要建立的多项式项数：");
    scanf("%d",&b);
    EnList(&LB,b);

    PrintList(&LA);
    printf("\n############分割线############\n");
    PrintList(&LB);
    printf("\n############分割线############\n");

    AddList(&LA,&LB);

    PrintList(&LA);
}