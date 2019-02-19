/*************************************************************************
	> File Name: 2.c
	> Author:Gin.TaMa 
	> Mail:1137554811@qq.com 
	> Created Time: 2018年12月26日 星期三 19时28分10秒
 ************************************************************************/

#include<stdio.h>

int num[10] = {0};// 标记哪个数字使用了
int jnum[10] = {0};//用来存储ｎ的阶乘

void init_jnum(){
    jnum[0] = jnum[1] = 1;
    for(int i = 2;i < 10;i ++){
        jnum[i] = jnum[i - 1] * i;
    }
}

int main(){
    int k = 999999;
    int m;
    init_jnum();
    for(int i = 9;i >=0 ;i--){
        m = k / jnum[i];
        k = k % jnum[i];
        for(int j = 0;j <10;j ++){
            if(num[j]){
                continue;
            }
            if(m == 0){
                printf("%d",j);
                num[j] = 1;
                break;
            }
            m --;
        }
    }
    printf("\n");
    return 0;
}
