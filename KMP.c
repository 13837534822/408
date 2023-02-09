#include<stdio.h>
#include<string.h>

#define lenght 12
//得到next数组
void get_next(char t[],int* next[],int length){
    int i=1,j=0;
    next[1]=0;
    while (i<length){
        if(j==0||t[i]==t[j]){
            i++;
            j++;
            next[i]=j;
        }else{
            j=next[j];
        }
    }   
}
//kmp算法
int Index_KMP(char s[],int slength,char t[],int tlength){
    int* next[tlength+1];
    get_next(t,&next,tlength+1);
    int i=1,j=1;
    while (i<=slength&&j<=tlength){
        if(j==0||s[i]==t[j]){
            i++;
            j++;
        }else{
            j=next[j];  //根据next数组来找到新的索引
        }
    }
    if(j>tlength){
        return i-tlength;
    }else{
        return -1;
    }
}
int main(){
    char str[]=" ababaaababaa";
    char target[]=" abaa";
    int str_lenght=12;
    int target_lenght=4;
    
    printf("%d",Index_KMP(str,str_lenght,target,target_lenght));
    return 0;
}