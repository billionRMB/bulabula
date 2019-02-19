/*************************************************************************
	> File Name: try.c
	> Author:Gin.TaMa 
	> Mail:1137554811@qq.com 
	> Created Time: 2019年01月05日 星期六 17时52分01秒
 ************************************************************************/

#include<stdio.h>
int factorial[10] = {0};
int num[10] = {0};

void init_fac(){
    factorial[0] = 1;
    for(int i = 1;i < 10;i ++){
        factorial[i] = factorial[i - 1] * i;
    }
}


int main(){
    init_fac();
    int k = 999999;
    for(int i = 9;i >= 0;i --){
        int m = k / factorial[i];
        k %= factorial[i];
        for(int i = 0;i <= 9;i++){
            if(num[i])continue;
            if(m == 0){
                printf("%d",i);
                num[i] = 1;
            }
            m --;
        }
    }
    printf("\n");
    return 0;
}
