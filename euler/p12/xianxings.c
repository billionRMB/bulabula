/*************************************************************************
	> File Name: xianxings.c
	> Author:Gin.TaMa 
	> Mail:1137554811@qq.com 
	> Created Time: 2018年12月22日 星期六 12时53分51秒
 ************************************************************************/

#include<stdio.h>
#define max 200000
int prime[max] = {0};

void init(){
    for(int i =2;i <= max;i++){
        if(!prime[i]) prime[++prime[0]] = i;
        for(int j = 1;j <=prime[0];j++){
            if(prime[j] * i >max) break;
            prime[i * prime[j]] =1;
            if(i % prime[j] == 0)break;//这个保证了 每个合数都是由最小的质因子筛去的，不多筛。
        }
    }
}

int main(){
    init();
    printf("%d\n",prime[10001]);
    return 0;
}
