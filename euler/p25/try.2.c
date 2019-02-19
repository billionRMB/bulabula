/*************************************************************************
	> File Name: try.2.c
	> Author:Gin.TaMa 
	> Mail:1137554811@qq.com 
	> Created Time: 2019年01月06日 星期日 19时00分50秒
 ************************************************************************/

#include<stdio.h>
#define max 1000
int Fib[2][max + 5] = {0};
void add(int * a,int * b){
    b[0] = b[0] > a[0] ? b[0]:a[0];
    for(int i = 1;i <= b[0];i ++){
        b[i] += a[i];
        if(b[i] < 10)continue;
        b[i + 1] += b[i] / 10;
        b[i] %= 10;
    }
    if(b[b[0] + 1])b[0]++;
}
int main(){
    int n = 0;
    Fib[0][0] = Fib[1][0] = 1;
    Fib[0][1] = 1;
    while(Fib[(n+1) % 2][0] < 1000){
        n ++;
        add(Fib[n%2],Fib[(n + 1)%2]);
    }
    printf("%d\n",n);
}
