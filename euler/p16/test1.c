/*************************************************************************
	> File Name: test1.c
	> Author:Gin.TaMa 
	> Mail:1137554811@qq.com 
	> Created Time: 2018年12月26日 星期三 10时21分14秒
 ************************************************************************/

#include<stdio.h>

int main(){
    int ans[500] = {0};
    ans[0] = ans[1] = 1;
    for(int i = 0;i <1000;i++){
        for(int i = 1;i <= ans[0];i++){
            ans[i] *= 2;
        }
        for(int i = 1;i <= ans[0];i ++){
            if(ans[i] < 10) continue;
            ans[i + 1] += ans[i]/10;
            ans[i] %= 10;
            ans[0] += (i == ans[0]);// 注意是长度 ans[0] += 1;
        }
    }
    for(int i = 1;i <= ans[0];i++){
        printf("%d",ans[i]);
    }
    printf("\n");
    int sum = 0;
    for(int i = 1;i <= ans[0];i ++){
        sum += ans[i];
    }
    printf("%d\n",sum);
    return 0;
}
