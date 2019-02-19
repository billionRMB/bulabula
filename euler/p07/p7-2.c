/*************************************************************************
	> File Name: p7-2.c
	> Author:Gin.TaMa 
	> Mail: 
	> Created Time: 2018年11月24日 星期六 12时56分08秒
 ************************************************************************/

#include<stdio.h>
#define MAX 100
//有问题好像 等着后期修改一下
int prime[MAX] = {0};

void init(){
    for(int i = 2 ; i*i <= MAX; i ++){
        if(prime[i]) continue;
        for(int j = i*i ;j <= MAX ;j+=i){
            prime[j] = 1;
        }
    }
    for(int i = 2 ; i < MAX;i ++){
        if(prime[i]) continue;
        prime[++prime[0]] = i;
    }
}

int main(){
    init();
    for(int i = 2;i < MAX;i++){
        for(int j = 1;j < prime[0];j++){
            if(i % prime[j]== 0){//！i % prime[0] 是有 bug的写法 。。。
                printf("%d(%d)\n",i,prime[j]);
                break;
            }
        }
    } 
    
    return 0;
}
