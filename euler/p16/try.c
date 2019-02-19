/*************************************************************************
	> File Name: try.c
	> Author:Gin.TaMa 
	> Mail:1137554811@qq.com 
	> Created Time: 2019年01月05日 星期六 00时40分56秒
 ************************************************************************/

#include<stdio.h>
#define max 2000
int ans[max] = {0};
int main(){
    ans[0] = ans[1] = 1;
    for(int i = 0;i < 1000;i ++){
        for(int i = 1;i <= ans[0];i++){
            ans[i] *= 2;
        }
        for(int i = 1;i <= ans[0];i ++){
            if(ans[i] < 10)continue;
            ans[i + 1] += ans[i]/10;
            ans[i] %= 10;
            ans[0] += (i == ans[0]);
        }
    }
    int sum = 0;
    for(int i = 1;i <= ans[0];i ++){
        sum += ans[i]; 
    }
    printf("%d\n",sum);
    return 0;
}
