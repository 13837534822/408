#include<stdio.h>
#include<stdbool.h>
//顺序栈
//------------------------------------------------
#define MaxSize 10
//顺序栈结构
typedef struct SqStack{
    int data[MaxSize];
    int top;  //栈顶指针
}SqStack;
//初始化
void InitSqStack(SqStack *s){
    s->top=-1;
}
//判断栈空
bool SqStackEmpty(SqStack *s){
    if(s->top==-1){
        return true;
    }
    return false;
}
//判断栈满
bool SqStackFull(SqStack *s){
    if(s->top==MaxSize-1){
        return true;
    }
    return false;
}
//进栈
bool Push(SqStack *s,int e){
    if(SqStackFull(s)){
        return false;
    }
    s->data[s->top+1]=e;
    s->top++;
    return true;
}
//出栈
bool Pop(SqStack *s,int *e){
    if(SqStackEmpty(s)){
        return false;
    }
    *e=s->data[s->top];
    s->top--;
    return true;
}
//读取栈顶元素
bool GetTop(SqStack *s,int *e){
    if(SqStackEmpty(s)){
        return false;
    }
    *e=s->data[s->top];
    return true;
}
int main(){
    SqStack stack;
    InitSqStack(&stack);
    Push(&stack,1);
    Push(&stack,2);
    int x;
    Pop(&stack,&x);
    printf("%d %d",x,stack.top);
    return 0;
}