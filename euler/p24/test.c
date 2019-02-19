/*************************************************************************
	> File Name: test.c
	> Author:Gin.TaMa 
	> Mail:1137554811@qq.com 
	> Created Time: 2019年01月25日 星期五 20时02分01秒
 ************************************************************************/

#include<stdio.h>

int num[10] = {0};

void init(){
    num[0] = 1;
    for(int i = 1;i < 10;i ++){
        num[i] = num[i - 1] * i;
    }
}

int ans[10] = {0};
int get_d(int k){
    for(int i = 0;i < 10;i ++){
        if(ans[i])continue;
        if(k == 0){
            ans[i] = 1;
            return i;
        }
        k --;
    }
}

int main(){
    init();
    int k = 999999;
    for(int i = 0;i < 10;i ++){
        printf("%d",get_d(k / num[9 - i]));
        k %= num[9- i];
    }
    return 0;
}
