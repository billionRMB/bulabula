/*************************************************************************
	> File Name: p22.c
	> Author:Gin.TaMa 
	> Mail: 
	> Created Time: 2018年11月20日 星期二 10时55分41秒
 ************************************************************************/

#include<stdio.h>
#define MAX_N 4000000
int main(){
    int a = 0,b = 1,c = 1,ans = 0;
    while(b <= MAX_N){
        c = a;
        a = b;
        b = c + b;
        if(b & 1) continue;
        ans += b;
    }
    printf("%d\n ", ans);    
    return 0;
}
