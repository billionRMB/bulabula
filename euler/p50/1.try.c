/*************************************************************************
	> File Name: 1.try.c
	> Author:Gin.TaMa 
	> Mail:1137554811@qq.com 
	> Created Time: 2019年01月13日 星期日 17时08分50秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<inttypes.h>
#define max 1000000

int prime[max + 5] ={0};
int64_t sum[max + 5] = {0};
void init(){
    for(int i = 2;i < max;i ++){
        if(!prime[i]){
            prime[++prime[0]] = i;
            sum[prime[0]] = sum[prime[0] - 1]+i;
        }
        for(int j = 1;j <= prime[0];j ++){
            if(i * prime[j] > max)break;
            prime[i * prime[j]] = 1;
            if(i % prime[j] == 0)break;
        }
    }
}

int is_prime(int64_t x){
    for(int i = 0;i < 30;i ++){
        int64_t a = rand() % (x - 1) + 1;
        int64_t ans = 1;
        int64_t p = x-1;
        while(p){
            if(p & 1)ans = a * ans % x;
            a = a * a % x;
            p >>= 1;
        }
        if(ans != 1)return 0;
    }
    return 1;
}

int main(){
    init();
    srand(time(0));
    int maxN = 21,maxP = 953;
    for(int i = 0;i <= prime[0];i ++){
        for(int j = i + maxN + 1;j  <= prime[0];j ++){
            if(sum[j] - sum[i] > max)break;
            if(is_prime(sum[j] - sum[i])){
                maxN = j - i;
                maxP = sum[j] - sum[i];
            }
        }
    }
    printf("%d %d\n",maxN,maxP);
    return 0;
}
