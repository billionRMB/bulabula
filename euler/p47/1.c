/*************************************************************************
	> File Name: 1.c
	> Author:Gin.TaMa 
	> Mail:1137554811@qq.com 
	> Created Time: 2018年12月28日 星期五 19时21分56秒
 ************************************************************************/

#include<stdio.h>

#define max 1000000

int prime[max + 5] = {0};
int dnum[max + 5] = {0};


void init(){
    for(int i = 2;i <= max;i ++){
        if(!prime[i]){
            prime[++prime[0]] = i;
            dnum[i] = 1;
        }
        for(int j = 1;j <= prime[0];j ++){//从　１　开始遍历ｐｒｉｍｍｅ
            if(i * prime[j] >= max){
                break;
            }
            prime[i * prime[j]] = 1;// 标记
            if(i % prime[j] == 0){
                dnum[i * prime[j]] = dnum[i];
                break;
            }else{
                dnum[i * prime[j]] = dnum[i] + 1; 
            }
        }
    }
}


int main(){
    init();
    for(int i = 210;i <= max - 4 ;i ++){
        if(dnum[i] == 4 && dnum[i + 1]==4 && dnum[i + 2] == 4 && dnum[i + 3]== 4){
            printf("%d\n",i);
            break;
        }
    }
    return 0;
}
