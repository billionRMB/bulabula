/*************************************************************************
	> File Name: test.c
	> Author:Gin.TaMa 
	> Mail:1137554811@qq.com 
	> Created Time: 2019年01月23日 星期三 14时53分23秒
 ************************************************************************/

#include<stdio.h>
#define max 10000
int prime[max + 5] = {0};
int dnum[max + 5] = {0};

void init(){
    for(int i = 2;i < max;i ++){
        if(!prime[i]){
            dnum[i] = 1;
            prime[++prime[0]]=i;
        }
        for(int j = 1;j <= prime[0];j ++){
            if(i * prime[j] > max)break;
            prime[i * prime[j]] = 1;
            if(i % prime[j] == 0)break;
        }
    }
}

int main(){
    init();
    for(int i = 1;i <= prime[0];i ++){
        for(int j = 1;prime[i] + 2 * j * j < max;j ++){
            dnum[prime[i] + j * j * 2] = 1;
        }
    }
    for(int i = 3;i < max;i += 2){
        if(!dnum[i]){
            printf("%d\n",i);
            break;
        }
    }
    return 0;
}
