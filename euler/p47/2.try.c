/*************************************************************************
	> File Name: 1.try.c
	> Author:Gin.TaMa 
	> Mail:1137554811@qq.com 
	> Created Time: 2019年01月12日 星期六 17时46分46秒
 ************************************************************************/

#include<stdio.h>
#define max 10000000

int prime[max + 5] = {0};
int mnum[max + 5] = {0};
int dnum[max + 5] = {0};

void init(){
    for(int i = 2;i < max;i ++){
        if(!prime[i]){
            prime[++prime[0]] = i;
            dnum[i] = 1;
        }
        for(int j = 1;j <= prime[0];j ++){
            if(i * prime[j] > max)break;
            prime[i * prime[j]] = 1;
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
    for(int i = 2;i < max - 4 ;i ++){
        if(dnum[i] == 4 && dnum[i + 1] == 4 
           && dnum[i + 2] == 4 &&dnum[i + 3] == 4){
               // 注意　１．因子个数和有多少个因子　2. {  }
               printf("%d\n",i);
               break;
           }
    }
    return 0;
}
