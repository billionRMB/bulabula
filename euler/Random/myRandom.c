/*************************************************************************
	> File Name: myRandom.c
	> Author:Gin.TaMa 
	> Mail:1137554811@qq.com 
	> Created Time: 2018年12月30日 星期日 22时45分15秒
 ************************************************************************/
#include<stdio.h>
#define MAX 100000

int prime[MAX + 5] = {0};

void init(){
    for(int i = 2;i < MAX;i ++){
        if(!prime[i])prime[++prime[0]] = i;
        for(int j = 1;j<=prime[0];j ++){
            if(i * prime[j] > MAX) break;
            prime[i * prime[j]] = 1;
            if(i % prime[j] == 0)break;
        }
    }
}

int quickMod(int a,int b,int c){
    int temp = a % c,ans = 1;
    while(b){
        if(b & 1) ans *= temp;
        temp *= temp;
        temp %= c;
        ans %= c;
        b >>= 1;
    }
    return ans;
}

int getLength(int a,int b){
    for(int i = 1;i * 2 <= b - 1;i ++){
        if((b - 1) % i)continue;
        if(quickMod(a,i,b) == 1){
            printf("%d %d %d\n",a,b,i);
            return i;
        } 
    }
    return b - 1;
}

int main(){
    init();
    int b = prime[2000];
    printf("%d\n",b);
    for(int i = 2;i < prime[0];i ++){
        if(getLength(prime[i],b) > 10000){
            printf("%d %d\n",prime[i],b);
            break;
        }
    }
}
