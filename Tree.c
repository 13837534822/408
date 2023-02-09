#include<stdio.h>
#include<stdbool.h>
# define MaxSize 100 
//顺序存储结构
//-------------------------------------------------------------------
//顺序结构的节点
typedef struct Arr_Node{
    int value;
    bool isEmpty;
}Arr_Node;

//初始化二叉树的顺序储存
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
int main(){
    Arr_Node t[MaxSize];
    Init_ArrTree(&t);
    printf("main:%d",GetLeft(60));
    return 0;
}