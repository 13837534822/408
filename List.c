//线性表
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
//静态分配
#define MaxSize 10
typedef struct{
    int data[MaxSize];
    int length;  
}SqList;

//初始化静态线性表
void InitList_SqList(SqList *L){
    for(int i=0;i<MaxSize;i++){
        L->data[i]=0;
    }
    L->length=0;
}
//插入元素
bool ListInsert(SqList *L,int i,int e){
    if(i<1||i>L->length+1){
        printf("超出插入范围\n");
        return false;
    }
    if(L->length>=MaxSize){
        printf("超出最大范围\n");
        return false;
    }
    for(int j=L->length;j>=i;j--){  //从插入位置往后将元素依次后挪
        L->data[j]=L->data[j-1];
    }
    L->data[i-1]=e;
    L->length++;
    return true;
}
//删除元素
int ListDelete(SqList *L,int i){
    if(i<1||i>L->length){
        printf("超出索引\n");
        return -1;
    }
    int e=L->data[i-1];
    for(int j=i;j<L->length;j++){
        L->data[j-1]=L->data[j];
    }
    L->length--;
    return e;
}
//获取元素
int GetElem(SqList *L,int i){
    if(i<1||i>L->length){
        printf("超出索引\n");
        return -1;
    }
    return L->data[i-1];
}
//按值查找第一个元素索引
int LocateElem(SqList *L,int e){
    for(int i=0;i<L->length;i++){
        if(L->data[i]==e){
            return i+1;
        }
    }
    return -1;
}
//--------------------------------------------------------
//动态分配

// typedef struct{
//     int *data;
//     int MaxLength;
//     int length;
// }SeqList;

// void InitList_SeqList(SeqList *L){
//     L->data=(int)malloc(MaxSize*sizeof(int));
//     for(int i=0;i<MaxSize;i++){
//         L->data[i]=0;
//     }
//     L->length=0;
//     L->MaxLength=MaxSize;
// }

// void IncreaseSize(SeqList *L,int addlen){
//     int *p=L->data;     //data也是个*data类型的指针
//     L->data=(int)malloc((L->MaxLength+addlen)*sizeof(int));
//     for(int i=0;i<L->length;i++){
//         L->data[i]=p[i];
//     }
//     L->MaxLength=L->MaxLength+addlen;
//     free(p);
// }
main(){
    SqList L;
    InitList_SqList(&L);
    ListInsert(&L,1,1);
    ListInsert(&L,2,2);
    int delete;
    delete=LocateElem(&L,2);
    //delete=ListDelete(&L,1);
    printf("%d\n",delete);
    printf("%d",L.data[0]);
}