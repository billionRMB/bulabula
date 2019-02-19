/*************************************************************************
	> File Name: 1.c
	> Author:Gin.TaMa 
	> Mail:1137554811@qq.com 
	> Created Time: 2018年12月29日 星期六 20时15分41秒
 ************************************************************************/

#include<stdio.h>
#define max 100000
int prime[max + 5] = {0};
double ans = 0;

int is_side(int x){

}

void init(){
    for(int i = 2;i < max;i++){
        if(!prime[i]){
            prime[++prime[0]] = i;
            int line = is_side(i);
            if(line != -1){
                ans ++;
                if(10 * ans /(double)(4 * line / 2 ) < 1){
                    printf("%d\n",line);
                    return ;
                }
            }
        }
        for(int j = 1;j <= prime[0];j++){
            if(i * prime[j] > max){
                break;
            }
            prime[i * prime[j]] = 1;
            if(i % prime[j] == 0){
                break;
            }
        }
    }

}

int main(){
    init();
    return 0;
}
