/*************************************************************************
	> File Name: 1.c
	> Author:Gin.TaMa 
	> Mail:1137554811@qq.com 
	> Created Time: 2019年01月02日 星期三 20时23分21秒
 ************************************************************************/
#include<math.h>
#include<stdio.h>
#define max 28123

int prime[max + 5] = {0};
int mnum[max + 5] = {0};
int dnum[max + 5] = {0};

void init(){
    for(int i = 2;i < max;i++){
        if(!prime[i]){
            prime[++prime[0]] = i;
            mnum[i] = 1;
            dnum[i] = i + 1;
        }
        for(int j = 1;j <= prime[0];j++){
            if(i * prime[j] >= max)break;
            prime[i * prime[j]] = 1;
            if(i % prime[j] == 0){
                mnum[i * prime[j]] = mnum[i] + 1;
                dnum[i * prime[j]] = dnum[i] /(1 - pow(prime[j],mnum[i] + 1)) * (1 - pow(prime[j],mnum[i] + 2));
                break;
            }else{
                mnum[i * prime[j]] = 1;
                dnum[i * prime[j]] = dnum[i] * dnum[prime[j]];
            }
        }
    }
}
int num[max + 5] = {0};
int main(){
    init();
    prime[0] = 0;
    for(int i = 12 ;i < max;i++){
        int temp = dnum[i] - i;
        if(temp > max || temp < 0)continue;// 注意　判断一下
        if(temp > i){
            prime[++prime[0]] = i;
            for(int j = 1;j <= prime[0];j++){
                if(prime[j] + i > max)break;
                num[prime[j] + i] = 1;
            }
        }
    }
    long long int sum = 0;
    for(int i = 1;i < max;i++){
        if(num[i])continue;
        sum += i;
    }
    printf("%lld\n",sum);
    return 0;
}
