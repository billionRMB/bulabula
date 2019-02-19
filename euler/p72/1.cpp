/*************************************************************************
	> File Name: 1.cpp
	> Author:Gin.TaMa 
	> Mail:1137554811@qq.com 
	> Created Time: 2018年12月29日 星期六 15时39分45秒
 ************************************************************************/

#include<iostream>
using namespace std;

#define max 1000000
int prime[max] = {0};
int phi[max] = {0};

void init(){
    for(int i = 2;i <= max;i++){
        if(!prime[i]){
            prime[++prime[0]] = i;
            phi[i] = i - 1;
        }
        for(int j = 1;j<= prime[0];j++){
            if(i * prime[j] > max){
                break;
            }
            prime[i * prime[j]] = 1;
            if(i % prime[j] == 0){
                phi[i * prime[j]] = phi[i] * prime[j]; 
                break;
            }else{
                phi[i * prime[j]] = phi[i] * 
                phi[prime[j]];
            }
        }
    }
    return ;
}

int main(){
    init();
    long long sum = 0;
    for(int i = 1;i <= max;i++){
        sum += phi[i];
    }
    printf("%lld\n",sum);
}
