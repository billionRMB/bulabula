/*************************************************************************
	> File Name: random.try.c
	> Author:Gin.TaMa 
	> Mail:1137554811@qq.com 
	> Created Time: 2019年01月13日 星期日 20时41分22秒
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

int get_num(int n){
    for(int i = 0;i < 10;i ++){
        if(ans[i])continue;
        if(n == 0){
            ans[i] = 1;
            return i;
        }
        n --;
    }
}

int main(){
    init();
    int n = 999999;
    for(int i = 0;i < 10;i ++){
        printf("%d",get_num(n / num[9 - i]));
        n %= num[9 - i];
    }
    printf("\n");
    return 0;
}
