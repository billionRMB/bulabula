/*************************************************************************
	> File Name: 2.c
	> Author:Gin.TaMa 
	> Mail:1137554811@qq.com 
	> Created Time: 2019年01月02日 星期三 12时14分39秒
 ************************************************************************/

#include<stdio.h>
#define max 1000000

int prime[max + 5] = {0};
int phi[max + 5] = {0};


void init(){
    for(int i = 2;i <= max;i++){
        if(!prime[i]){
            prime[++prime[0]] = i;
            phi[i] = i - 1;
        }
        for(int j = 1;j <= prime[0];j++){
            if(i * prime[j] > max)break;
            prime[i * prime[j]] = 1;
            if(i % prime[j]==0){
                phi[i * prime[j]] = phi[i] * prime[j];
                break;
            }else{
                phi[i * prime[j]] = phi[i] * phi[prime[j]];
            }
        }
    }
}


int main(){
    init();
    long long int sum = 0;
    for(int i = 1;i <= max;i++){
        sum += phi[i];
    }
    printf("%lld\n",sum);
}
