/*************************************************************************
	> File Name: staticTest.c
	> Author:Gin.TaMa 
	> Mail:1137554811@qq.com 
	> Created Time: 2019年03月20日 星期三 14时42分53秒
 ************************************************************************/

#include<stdio.h>
long long int fib(){
    static long long int first = 0;
    static long long int second = 1;
    long long int out = first + second;
    first = second;
    second = out;
    return out;
}
int main(){
    for(int i = 0;i < 10;i ++){
        printf("%lld\n",fib());
    }
    return 0;
}
