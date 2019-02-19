/*************************************************************************
	> File Name: 2.c
	> Author:Gin.TaMa 
	> Mail:1137554811@qq.com 
	> Created Time: 2018年12月22日 星期六 14时26分09秒
 ************************************************************************/

#include<stdio.h>
#define max 1000000
// 感觉没问题 但是太慢了？？？
int prime[max] = {0};

void init(){
    for(int i = 2;i < max;i ++){
        int ans = 1;
        if(!prime[i])prime[++prime[0]] = i;
        for(int j = 1;j <= prime[0];j++){
            if(i * prime[j] > max)break;
            prime[i * prime[j]] = 1;
            if(i % prime[j] == 0) break;
        }
        for(int j = 1;j <= prime[0];j++){
            int x = i;
            int count = 0;
            while(x % prime[j] == 0){
                count ++;
                x /= prime[j];
            }
            ans = (count + 1)*ans;
        }
        if(i > 100)break;
        if(ans > 500){
            printf("%d\n",i);
            break;
        }
    }
}

int main(){
    init();
    return 0;
}
