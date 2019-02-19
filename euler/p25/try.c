/*************************************************************************
	> File Name: try.c
	> Author:Gin.TaMa 
	> Mail:1137554811@qq.com 
	> Created Time: 2019年01月05日 星期六 19时51分42秒
 ************************************************************************/

#include<stdio.h>
#define max 1005

int Fib[3][max] = {0};

void add(int * a,int * b,int * c){
    c[0] = (a[0] > b[0] ? a[0] : b[0]);
    for(int i = 1;i <= c[0];i ++){
        c[i] = a[i] + b[i];
    }
    for(int i = 1;i <= c[0];i ++){
        if(c[i] < 10)continue;
        c[i + 1] += c[i] / 10;
        c[i] %= 10;
    }
    if(c[c[0] + 1])c[0] ++;
}

int main(){
    Fib[0][0] = Fib[1][0] = Fib[2][0] = 1;
    Fib[1][1] = 1;
    int n = 0;
    while(Fib[(n + 2)%3][0] < 1000){
        n ++;
        add(Fib[n % 3],Fib[(n + 1)%3],Fib[(n + 2)%3]);
    }
    printf("%d\n",n);
    return 0;
}
