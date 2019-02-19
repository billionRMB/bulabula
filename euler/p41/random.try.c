/*************************************************************************
	> File Name: random.try.c
	> Author:Gin.TaMa 
	> Mail:1137554811@qq.com 
	> Created Time: 2019年01月20日 星期日 22时56分23秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int ml_test(int x){
    for(int i = 0;i < 30;i ++){
        int a = rand() % (x - 1) + 1;
        int p = x - 1;
        int ans = 1;
        // 一定对初始值进行检验
        while(p){
            if(p & 1)ans = ans * a % x;
            a = a * a % x;
            p >>= 1;
        }
        if(ans != 1)return 0;
    }
    return 1;
}
int main(){
    srand(time(0));
    int num[9];
    for(int i = 1;i <= 7;i++){
        num[i - 1] = i;
    }
    return 0;
}
