/*************************************************************************
	> File Name: 1.c
	> Author:Gin.TaMa 
	> Mail:1137554811@qq.com 
	> Created Time: 2018年12月21日 星期五 19时11分11秒
 ************************************************************************/

#include<stdio.h>

int w[9] = {0,1,2,5,10,20,50,100,200};

int f(int k,int n){
    if(k == 1) return 1;
    if(n == 0)return 1;
    if(n < 0)return 0;
    return f(k-1,n) + f(k, n - w[k]);
}
int main(){
    printf("%d\n",f(8,200));
    return 0;
}
