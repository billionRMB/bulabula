/*************************************************************************
	> File Name: 1.c
	> Author:Gin.TaMa 
	> Mail:1137554811@qq.com 
	> Created Time: 2018年12月29日 星期六 09时21分37秒
 ************************************************************************/

#include<stdio.h>
#define max 1000000
int prime[max + 5];

static int my_seed = 66; 

int my_rand(){
    #define i my_seed
    do{
        i = i * 31 % 17389; 
    }while(i > 10000);
    return i;
    #undef i
}

void check(){
    int vis[10001] = {0};
    for(int i = 0;i < 10000;i ++){
        int temp = my_rand();
        if(vis[temp]){
            printf("error\n");
        }
        vis[temp] = 1;
    }
    printf("yes\n");
}

void init(){
    for(int i = 2;i <= max;i ++){
        if(!prime[i])prime[++prime[0]] = i;
        for(int j = 1;j <= prime[0];j++){
            if(i * prime[j] > max) break;
            prime[i * prime[j]] = 1;
            if(i % prime[j] == 0) break;
        }
    }
}

int quick_mod(int a,int b,int c){
    int ans = 1, temp = a % c;
    while(b){
        if(b & 1) ans *= temp;
        temp *= temp;
        temp %= c;
        ans %= c;
        b >>= 1;
    }
    return ans;
}

int get_len(int a,int b){
    for(int i = 1;i < b -1;i++){
        if((b - 1) % i) continue;
        if(quick_mod(a,i,b) == 1)return i;
    }
}

int main(){
    init();
    int b = prime[2000];
    for(int i = 2;i < b;i++){
        if(get_len(prime[i],b) >= 10000){
            printf("%d %d\n",prime[i],b);
            break;
        } 
    }
    check();
    return 0;
}
