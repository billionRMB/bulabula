/*************************************************************************
	> File Name: try.c
	> Author:Gin.TaMa 
	> Mail:1137554811@qq.com 
	> Created Time: 2019年01月03日 星期四 18时20分58秒
 ************************************************************************/

#include<stdio.h>

int gcd(int a,int b){
    if(!b) return a;
    return gcd(b,a%b);
}

int main(){
    int ans = 1;
    for(int i = 1;i <= 20;i ++){
        if(ans % i == 0)continue;
        ans = ans * i / gcd(ans,i);
    }
    printf("%d\n",ans);
}
