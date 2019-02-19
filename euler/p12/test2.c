/*************************************************************************
	> File Name: test2.c
	> Author:Gin.TaMa 
	> Mail:1137554811@qq.com 
	> Created Time: 2018年12月25日 星期二 22时32分36秒
 ************************************************************************/

#include<stdio.h>
#define max 100000
int prime[max + 5] = {0};
int dnum[max + 5] = {0};
int num[100000] = {0};
int ssnum[100000] = {0};
void i(){
    for(int i = 2;i <= 100000;i ++ ){
        if(!ssnum[i]){
            ssnum[++ssnum[0]]= i;
            num[i] = 2;
        }
        for(int j = 1;j <= ssnum[0];j++){
            if(ssnum[j] * i > 100000)break;
            ssnum[ssnum[j] * i] = 1;
            if(i % ssnum[j] == 0){
                int x = i;
                int count = 0;
                while(x % ssnum[j] == 0){
                    x /= ssnum[j];
                    count ++;
                }
                num[i * ssnum[j]] = num[i] / (count + 1) * (count + 2);
                break;
            }else{
                num[i * ssnum[j]] = num[i] * num[ssnum[j]];
            }
        }
    }
}

void init2(){
    for(int i = 2;i <= max;i ++){
        if(!prime[i]){
            prime[++prime[0]] = i;
            dnum[i] = 2; 
        }
        for(int j = 1;j <= prime[0];j++){
            if(prime[j] * i > max)break;
            prime[i * prime[j]] = 1;
            if(i % prime[j] == 0){
                int x = i,count = 0;
                while(x % prime[j] == 0){
                    count ++;
                    x /= prime[j];
                }
                dnum[prime[j] * i] = dnum[i] /(count + 1) * (count + 2);
                break;
            }else{
                dnum[prime[j] * i] = dnum[i] * dnum[prime[j]];
            }
        }
    }
}
void init(){
    for(int i = 2;i <= max;i ++){
        if(!prime[i]){
            prime[++prime[0]] = i;
            dnum[i] = 2;
        }
        for(int j = 1;j <= prime[0];j ++){
            if(prime[j] * i > max) break;
            prime[prime[j] * i] = 1;
            if(i % prime[j]==0){
                int temp = i,bj = 0;
                while(temp % prime[j] == 0){
                    temp /= prime[j];
                    bj ++;
                }
                dnum[prime[j] * i] = dnum[i]/(bj + 1) * (bj +2);
                break;
            }else{
                dnum[prime[j] * i] = dnum[prime[j]] * dnum[i];
            } 
        }
    } 
}




int get_n(int i){
    if(i & 1)return num[i] * num[(i + 1)/2];
    return num[i/2] * num[i + 1];
}

int fac_n(int x){
    printf("%d\n",x);
    if(x & 1) return dnum[x] * dnum[(x + 1)/2];
    return dnum[x + 1] * dnum[x / 2];
}

int main(){
    i();
    int i = 1;
    while(get_n(i) < 500){
        i++;
    }
    printf("%d\n",i * (i+1)/2);
    return 0;
}
