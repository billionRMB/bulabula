/*************************************************************************
	> File Name: sumprime.c
	> Author:Gin.TaMa 
	> Mail:1137554811@qq.com 
	> Created Time: 2018年12月28日 星期五 20时15分01秒
 ************************************************************************/

#include<stdio.h>
#include<math.h>
#define max 10000
int prime[max + 5] = {0};
int dnum[max + 5] = {0};
int mnum[max + 5] = {0};

int clacu(int a,int b){
    return (1 - pow(a,b+1))/(1 -a);
}

void init(){
    for(int i = 2;i <= max;i ++){
        if(!prime[i]){
            prime[++prime[0]] = i;
            dnum[i] = i + 1;
            mnum[i] = 1;
        }
        for(int j = 1;j <= prime[0];j ++){
            if(i * prime[j] > max)break;
            prime[i * prime[j]] = 1;
            if(i % prime[j] == 0){
                mnum[i * prime[j]] = mnum[i] + 1;
                dnum[i * prime[j]] = dnum[i]
                    / clacu(prime[j],mnum[i]) 
                    * clacu(prime[j],mnum[i]+1);
                break;
            }else{
                dnum[i * prime[j]] = dnum[i] * dnum[prime[j]];
                mnum[i * prime[j]] = 1;
            }
        }
    }
}

int main(){
    init();
    for(int i = 2;i <= 50;i++){
        printf("%d -> %d\n",i,dnum[i]);
    }
    return 0;
}
// 21 23
