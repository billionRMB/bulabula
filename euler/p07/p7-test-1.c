/*************************************************************************
	> File Name: p7-test-1.c
	> Author:Gin.TaMa 
	> Mail: 
	> Created Time: 2018年11月25日 星期日 16时22分08秒
 ************************************************************************/

#include<stdio.h>
#define max 200000

int prime[max + 5] = {0};

void init(){
    for(int i = 2; i * i < max ; i++){
        if(prime[i]) continue;
        for(int j = i*i; j < max; j+=i){
            prime[j] = 1;
        }
    }
    for(int i = 2;i < max;i++){
        if(prime[i])continue;
        prime[++prime[0]] = i;
    }
}

//这样在循环的时候就完成了存储的操作了

void init2(){
    for(int i = 2;i < max;i ++){
        if(prime[i])continue;
        prime[++prime[0]] = i;
        if(i*i < 0)continue;//注意 因为 i 是 从2 到 max 所以i * i 会爆掉 爆掉后 就小于 0 了。
        for(int j = i*i ;j < max-i;j += i){
            prime[j] = 1;
        }
    }
}

int main(){
    init2();
    printf("%d\n",prime[10001]);
    return 0;
}
