#include<stdio.h>
#include<stdbool.h>
# define MaxSize 100 
//顺序存储结构
//------------------------------------------------------------------
//顺序结构的节点 （从1位置开始存）
typedef struct Arr_Node{
    int value;
    bool isEmpty;
}Arr_Node;

//初始化二叉树的顺序存储
void Init_ArrTree(Arr_Node t[]){
    
    for(int i=0;i<MaxSize;i++){
        t[i].isEmpty=true;
    }
    printf("%d\n",t[3].isEmpty);
}
int GetLeft(int i){
    if(2*i>=MaxSize||2*i<1){
        return -1;
    }else{
        return 2*i;
    }
}
int GetRight(int i){
    if((2*i+1)>=MaxSize||(2*i+1)<1){
        return -1;
    }else{
        return 2*i+1;
    }
}
int GetParent(int i){
    if(i/2<1){
        return -1;
    }else{
        return i/2;
    }
}

//----------------------------------------------------------------
//链式存储
typedef struct Link_Node{
    int data;
    struct Link_Node *left;
    struct Link_Node *right;
}Link_Node;


int main(){
    Arr_Node t[MaxSize];
    // Init_ArrTree(&t);
    // printf("main:%d",GetParent(1));
    Link_Node node1={1};
    Link_Node node2={2};
    Link_Node node3={3};
    Link_Node node4={4};
    node1.left=&node2;
    node1.right=&node3;
    node2.left=&node4;
    printf("%d",node1.left->left->data);
    return 0;
}