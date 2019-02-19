/*************************************************************************
	> File Name: random.try.c
	> Author:Gin.TaMa 
	> Mail:1137554811@qq.com 
	> Created Time: 2019年01月17日 星期四 20时03分32秒
 ************************************************************************/

#include<stdio.h>
#define max 10000
int prime[max + 5] = {0};
int num[max + 5] = {0};
void init(){
    for(int i = 2;i < max;i ++){
        if(!prime[i]){
            prime[++prime[0]] = i;
            num[i] = 1;
        }
        for(int j = 1;j <= prime[0];j ++){
            if(i * prime[j] > max)break;
            prime[i * prime[j]] = 1;
            if(i % prime[j] == 0)break;
            // 注意ｂｕｇ
        }
    }
}
int main(){
    init();
    for(int i = 1;i <= prime[0];i ++){
        for(int j = 1;prime[i] + 2 * j * j < max;j ++){
            num[prime[i] + 2 * j * j] = 1;
        }
    }
    for(int i = 3;i < max;i += 2){
        if(num[i])continue;
        printf("%d\n",i);
        break;
    }
    return 0;
}
