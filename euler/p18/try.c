/*************************************************************************
	> File Name: try.c
	> Author:Gin.TaMa 
	> Mail:1137554811@qq.com 
	> Created Time: 2019年01月05日 星期六 09时08分58秒
 ************************************************************************/

#include<stdio.h>

#define max 20

#define MAX(a,b) ((a) > (b) ? (a) : (b))

int num[max][max] = {0};

void solve(){
    for(int i = 13;i>= 0;i --){
        for(int j = 0;j <= i;j ++){
            num[i][j] = num[i][j] + MAX(num[i + 1][j],num[i + 1][j + 1]);
        }
    }
}

int main(){
    for(int i = 0;i < 15;i ++){
        for(int j = 0;j <= i;j ++){
            scanf("%d",&num[i][j]);
        }
    }
    solve();
    printf("%d\n",num[0][0]);
    return 0;
}
