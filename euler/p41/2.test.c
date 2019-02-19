/*************************************************************************
	> File Name: 2.test.c
	> Author:Gin.TaMa 
	> Mail:1137554811@qq.com 
	> Created Time: 2019年01月25日 星期五 16时22分26秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int ml_test(int x){
    for(int i = 0;i < 30;i ++){
        int a = rand()%(x - 1) + 1;
        int p = x - 1;
        int ans = 1;
        while(p){
            if(p & 1) ans = ans * a % x;
            a = a * a % x;
            p >>= 1;
        }
        if(ans != 1)return 0;
    }
    return 1;
}

int main(){
    srand(time(0));
    for(int i = 2;i < 40;i ++){
        if(ml_test(i))printf("%d\n",i);
    }
    return 0;
}
