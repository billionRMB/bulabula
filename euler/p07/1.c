/*************************************************************************
	> File Name: 1.c
	> Author:Gin.TaMa 
	> Mail:1137554811@qq.com 
	> Created Time: 2018年12月26日 星期三 11时45分45秒
 ************************************************************************/

#include<stdio.h>
#define max 100000

int prime[max + 5] = {0};

void init(){
    for(int i = 2;i < max;i ++){
        if(!prime[i])continue;
        prime[++prime[0]] = i;
        for(int j = 2;j <= i;j ++){
            if(prime[i] * j > max) break;
            prime[prime[i] * j] = 1;
        }
    }
}
void init2(){
    for(int i = 2;i < max;i ++){
        if(!prime[i]){
            prime[++prime[0]] = i;
        }
        for(int j = 1;j <= prime[0];j ++){
            if(i * prime[j] > max) break;
            prime[i * prime[j]] = 1;
            if(i % prime[j] == 0)break;
        }
    }
}


int main(){
    return 0;
}
