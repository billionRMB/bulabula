/*************************************************************************
	> File Name: p7-1.c
	> Author:Gin.TaMa 
	> Mail: 
	> Created Time: 2018年11月24日 星期六 10时37分28秒
 ************************************************************************/

#include<stdio.h>
# define MAX_N 200000

int prime[MAX_N+ 5] = {0};

void init(int aim){
    for(int i = 2; i*i <= MAX_N;i++){
        if(prime[i]) continue;
        for(int j =i*i ; j <= MAX_N ; j += i){//从 i×i 避免 2 2 * 3 与 3 * 2
            prime[j] = 1;
        }
    }
    for(int i = 2 ;i < MAX_N;i++){
        if(prime[i])continue;
        prime[++prime[0]]=i;//***//
        if(prime[0] > aim ){
            return ;
        }
    }
    return ;
}

int main(){
    init(10001);
    printf("%d\n",prime[10001]);
    return 0;
}
