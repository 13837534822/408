#include<stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct DNode{
    int data;
    struct DNode* next;
}DNode;
bool Init_DLinkList(DNode *head){
    malloc(sizeof(DNode));
    if(head==NULL){
        return false;
    }
    head->data=0;
    head->next=NULL;
    return true;
}
int main(){
    DNode head;
    Init_DLinkList(&head);
    printf("Node-data: %d",head.data);
    printf("%d",&head);
    return 0;
} //测试测试1111