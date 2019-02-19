/*************************************************************************
	> File Name: test.c
	> Author:Gin.TaMa 
	> Mail:1137554811@qq.com 
	> Created Time: 2019年01月25日 星期五 16时33分30秒
 ************************************************************************/

#include<stdio.h>
#define max 200000
int prime[max] = {0};
int main(){
    for(int i = 2;i < max;i ++){
        if(!prime[i])prime[++prime[0]] = i;
        for(int j = 1;j <= prime[0];j ++){
            if(i * prime[j] > max)break;
            prime[i * prime[j]] = 1;
            if(i % prime[j] == 0)break;
        }
    }
    printf("%d\n",prime[10001]);
    return 0;
}
