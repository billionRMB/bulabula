/*************************************************************************
	> File Name: 1.c
	> Author:Gin.TaMa 
	> Mail:1137554811@qq.com 
	> Created Time: 2019年01月09日 星期三 22时19分58秒
 ************************************************************************/

#include<stdio.h>
int gcd(int a,int b){
    if(!b)return a;
    return gcd(b,a%b);
}

int main(){
    int a0,b0,a1,b1;
    for(int a = 1;a < 10;a ++){
        for(int b = a+1 ;b < 10;b++){
            if(gcd(a,b) == 1)continue;
            for(int i = 1;i < 10;i ++){
                if(i == b || i == a)continue;
                if(gcd(i,b)!=1||gcd(i,a)!=1)continue;
                if(gcd(a*10 + i,i * 10 + b)!=1){
                    printf("%d%d %d%d\n",a,i,i,b);
                }
            }
        }
    }
}
