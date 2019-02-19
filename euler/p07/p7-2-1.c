/*************************************************************************
	> File Name: p7-2-1.c
	> Author:Gin.TaMa 
	> Mail: 
	> Created Time: 2018年11月24日 星期六 14时41分53秒
 ************************************************************************/

#include<stdio.h>
#define max  10000

int prime[max + 5] = {0};
void init(){
    for(int i = 2 ; i*i <= max ; i++){
        if(prime[i])continue;
        for(int j = i; j <= max ;j+=i){
            if(prime[j])continue;//有这一句话就是找出的最小的素因子没有就是最大的素因数
            prime[j] = i;//**//
        }
    }
}
int main(){
    int n;
    init();
    while(~scanf("%d",&n)){
        printf("%d(%d)",n,prime[n]);
    }
    return 0;
}
