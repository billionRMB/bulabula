/*************************************************************************
	> File Name: try.c
	> Author:Gin.TaMa 
	> Mail:1137554811@qq.com 
	> Created Time: 2019年01月09日 星期三 15时55分30秒
 ************************************************************************/

#include<stdio.h>
int val[9] = {0,1,2,5,10,20,50,100,200};

int mm[9][200] = {0};

int f(int k,int w){
    if(k == 1||w == 0)return 1;
    if(w < 0)return 0;
    if(!mm[k][w])mm[k][w] = f(k,w - val[k]) + f(k - 1,w);
    return mm[k][w];
}


int main(){
    printf("%d\n",f(8,200));
    return 0;
}
