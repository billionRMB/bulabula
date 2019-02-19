/*************************************************************************
	> File Name: 1.c
	> Author:Gin.TaMa 
	> Mail:1137554811@qq.com 
	> Created Time: 2018年12月26日 星期三 18时08分50秒
 ************************************************************************/

#include<stdio.h>
#include<inttypes.h>
int dnum[10] = {0};// 标记哪个数字使用了
int jnum[10] = {0};//用来存储ｎ的阶乘 即　状态数

void init_jnum(){
    dnum[0] = jnum[0] = 1;
    for(int i = 1;i < 10;i ++){
        dnum[i] = 1;
        jnum[i] = jnum[i - 1] * i; 
    }
    return ;
}

int get_num(int n,int k){
    int index = (k / jnum[n]) + 1,i = -1;
    while(index > 0){
        i ++;
        index -= dnum[i];
    }
    dnum[i] = 0;
    return i;
}

int main(){
    init_jnum();
    int n,k;
    scanf("%d%d",&n,&k);
    k -= 1;
    for(int i = n - 1;i >= 0;i--){
        int num = get_num(i,k);
        printf("%d",num);
        k %= jnum[i];
    }
    printf("\n");
    return 0;
}

