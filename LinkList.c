#include<stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//普通链表
//-----------------------------------------------------------------
typedef struct DNode{
    int data;
    struct DNode* next;
}DNode;
//初始化
bool Init_DLinkList(DNode *head){  
    malloc(sizeof(DNode));
    if(head==NULL){
        return false;
    }
    head->data=0;
    head->next=NULL;
    return true;
}
//在按位序插入节点
bool ListInsert(DNode *head,int i,int e){
    if(i<1){
        return false;
    }
    DNode *p;
    int j=0;
    p=head;
    while(p!=NULL&&j<i-1){  //指针p指向i的前一个节点
        p=p->next;
        j++;
    }
    if(p==NULL){
        return false;
    }
    DNode *s=(DNode*)malloc(sizeof(DNode)); //开辟空间
    s->next=p->next;
    p->next=s;
    s->data=e;
    return true;
}
//循环遍历链表
void Travel(DNode *head){
    while(head!=NULL){
        printf("%d ",head->data);
        head=head->next;
    }
}
//删除节点
int main(){
    DNode head;
    Init_DLinkList(&head);
    ListInsert(&head,1,1);
    ListInsert(&head,2,3);
    ListInsert(&head,2,2);
    Travel(&head);
    printf("Node-data: %d",head.data);
    return 0;
} 