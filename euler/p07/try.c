/*************************************************************************
	> File Name: try.c
	> Author:Gin.TaMa 
	> Mail:1137554811@qq.com 
	> Created Time: 2019年01月03日 星期四 23时17分12秒
 ************************************************************************/

#include<stdio.h>
#define max 200000
int prime[max + 6] = {0};

void init(){
    for(int i = 2;i < max;i ++){
        if(!prime[i])prime[++prime[0]] = i;
        for(int j = 1;j <= prime[0];j++){
            if(i * prime[j] > max)break;
            prime[i * prime[j]] = 1;
            if(i % prime[j] == 0)break;
        }
    }
}

int main(){
    init();
    int a = prime[0];
    int b = prime[10001];
    printf("%d %d\n",a,b);
}
