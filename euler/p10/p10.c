/*************************************************************************
	> File Name: p10.c
	> Author:Gin.TaMa 
	> Mail: 
	> Created Time: 2018年11月24日 星期六 11时19分41秒
 ************************************************************************/

#include<stdio.h>
#include<inttypes.h>
#define MAX_N  2000000
int32_t prime[MAX_N + 2] = {0};
//要使用 32位 和 64 位来存储 注意一下 数据范围类型和 inttypes.h的 数据类型的用法
void init(){
    int ans = 0;
    for(int64_t i = 2 ; i*i <= MAX_N;i ++){
        if(prime[i])continue;
        for(int64_t j = i*i ; j < MAX_N; j += i ){
            prime[j] = 1;
        }
    }
}

int main(){
    init();
    int64_t ans = 0;
    for(int i = 2; i < MAX_N ;i++){
        if(prime[i])continue;
        ans += i;
    }
    printf("%"PRId64"\n",ans);
    return 0;
}
