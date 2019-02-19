/*************************************************************************
	> File Name: test.cpp
	> Author:Gin.TaMa 
	> Mail:1137554811@qq.com 
	> Created Time: 2019年01月25日 星期五 19时47分07秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<vector>
#include<math.h>
using namespace std;
#define max 100000

int prime[max + 5] = {0};
int dnum[max + 5] = {0};
int mnum[max + 5] = {0};
void init(){
    for(int i = 2;i < max;i ++){
        if(!prime[i]){
            prime[++prime[0]] = i;
            mnum[i] = 1;
            dnum[i] = i + 1;
        }
        for(int j = 1;j <= prime[0];j ++){
            if(i * prime[j] > max){
                break;
            }
            prime[i * prime[j]] = 1;
            if(i % prime[j] == 0){
                mnum[i * prime[j]] = mnum[i] + 1;
                dnum[i * prime[j]] = dnum[i] / (1 - pow(prime[j],mnum[i] + 1)) * (1 - pow(prime[j],mnum[i] + 2));
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
    return 0;
}
