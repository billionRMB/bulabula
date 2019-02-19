/*************************************************************************
	> File Name: 1.try.c
	> Author:Gin.TaMa 
	> Mail:1137554811@qq.com 
	> Created Time: 2019年01月12日 星期六 17时00分34秒
 ************************************************************************/

#include<stdio.h>
#define max 10000

int prime[max + 5] = {0};
int num[max + 5] = {0};
void init(){
    prime[1] = 1;
    for(int i = 1;i < max;i ++){
        if(!prime[i]){
            prime[++prime[0]] = i;
            num[i] = 1;
        }
        for(int j = 1;j <= prime[0];j ++){
            if(i * prime[j] > max) break;
            prime[i * prime[j]] = 1;
            if(i % prime[j] == 0){
                break;
            }
        }
    }
}


int main(){
    init();
    for(int i = 1;i <= prime[0];i ++){
        for(int j = 1;1;j ++){
            int temp = prime[i] + 2 * j * j;
            if(temp > max)break;
            num[temp] = 1;
        }
    }
    for(int i = 1; 2 * i + 1 < max;i ++){
        if(num[2 * i + 1])continue;
        printf("%d\n",i * 2 + 1);
        break;
    }
    return 0;
}
