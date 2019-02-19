/*************************************************************************
	> File Name: p2-2.c
	> Author:Gin.TaMa 
	> Mail: 
	> Created Time: 2018年11月17日 星期六 15时19分37秒
 ************************************************************************/

#include<stdio.h>

#define MAX_N 4000000

int main(){
    int a = 1,b = 1,ans = 0;
    while (b <= MAX_N){
        if( (b & 1) == 0) ans += b;
        a = a+b;
        //将 a+b 与 b 交换
        a ^= b;
        b ^= a;
        a ^= b;
    }
    printf("%d\n",ans);
    return 0;
}
