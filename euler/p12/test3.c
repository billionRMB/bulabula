/*************************************************************************
	> File Name: test3.c
	> Author:Gin.TaMa 
	> Mail:1137554811@qq.com 
	> Created Time: 2018年12月26日 星期三 09时46分30秒
 ************************************************************************/

#include<stdio.h>
#define max 100000

int prime[max + 5] = {0};
int dnum[max + 5] = {0};
int mnum[max + 5] = {0};

int num(int x){
    return x * (x + 1)/2;
}

int init(){
    for(int i = 2;i <= max;i ++){
        if(!prime[i]){
            prime[++prime[0]] = i;
            dnum[i] = 2;
            mnum[i] = 1;
        }
        for(int j = 1;j <= prime[0];j ++){
            if(prime[j] * i > max) break;
            prime[i * prime[j]] = 1;
            if(i % prime[j] == 0){
                dnum[prime[j] * i] = dnum[i] / (mnum[i] + 1)*(mnum[i] + 2);
                mnum[prime[j] * i] = mnum[i] + 1;
                break;
            }else{
                dnum[prime[j] * i] = dnum[i] * dnum[prime[j]];
                mnum[prime[j] * i] = 1;
            }
        }
    }
}

int get_n(int i){
    if(i & 1)return dnum[(i + 1)/2]  * dnum[i];
    return dnum[i / 2] * dnum[i + 1];
}


int main(){
    int i = 1;
    init();
    while(get_n(i)<500)i++;
    printf("%d\n",num(i));
    return 0;
}
