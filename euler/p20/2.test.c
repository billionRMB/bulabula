/*************************************************************************
	> File Name: 2.test.c
	> Author:Gin.TaMa 
	> Mail:1137554811@qq.com 
	> Created Time: 2019年01月25日 星期五 17时10分38秒
 ************************************************************************/

#include<stdio.h>
#include<math.h>
#define max 10000
int prime[max + 5] = {0};
int dnum[max + 5] = {0};
int mnum[max + 5] = {0};

void init(){
    for(int i = 2;i < max;i ++){
        if(!prime[i]){
            prime[++prime[0]] = i;
            dnum[i] = i + 1;
            mnum[i] = 1;
        }
        for(int j = 1;j <= prime[0];j ++){
            if(i * prime[j] > max)break;
            prime[i * prime[j]] = 1;
            if(i % prime[j] == 0){
                dnum[i * prime[j]] = dnum[i] / (1 - pow(prime[j],mnum[i]+1))*(1 - pow(prime[j],mnum[i] + 2));
                mnum[i * prime[j]] = mnum[i] + 1;
                break;
            }else{
                dnum[i * prime[j]] = dnum[i] * dnum[prime[j]];
                mnum[i * prime[j]] = 1;
            }
        }
    }
}
void init2(){
    for(int i = 2;i < max;i ++){
        if(!prime[i]){
            prime[++prime[0]] = i;
            mnum[i] = 1;
            dnum[i] = i + 1;
        }
        for(int j = 1;j <= prime[0];j ++){
            if(i * prime[j] > max)break;
            prime[i * prime[j]] = 1;
            if(i % prime[j] == 0){
                mnum[i * prime[j]] = mnum[i] + 1;
                dnum[i * prime[j]] = dnum[i]/(1 - pow(prime[j],mnum[i]+1))*(1-pow(prime[j],mnum[i]+2));
                break;
            }else{
               mnum[i * prime[j]] = 1; 
                dnum[i * prime[j]] = dnum[i] * dnum[prime[j]];
            }
        }
    }
}
int main(){
    init2();
    for(int i = 2;i < max;i ++){
        int b = dnum[i] - i;
        if(b > max)continue;
        if(dnum[b] - b == i && i != b){
            printf("%d %d\n",b,i);
        }
    }
    return 0;
}
