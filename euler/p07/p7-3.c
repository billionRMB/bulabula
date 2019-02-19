/*************************************************************************
	> File Name: p7-3.c
	> Author:Gin.TaMa 
	> Mail: 
	> Created Time: 2018年11月24日 星期六 15时37分28秒
 ************************************************************************/
//线性筛。。
#include<stdio.h>
#define max  200000
int prime[max] = {0};

void init(){
    for(int i = 2;i <= max;i++){
        if(!prime[i]) prime[++prime[0]] = i;
        //先加一 再写入的 可以证明 这一定是一个质数
        for(int j = 1;j <= prime[0];j++){
            if(prime[j] * i > max ) break;
            prime[prime[j] * i] = 1;
            if(i % prime[j] == 0) break;
        }
    }
    return;
}

int main(){
    init();
    printf("%d\n",prime[10001]);
    return 0;
    
}
