/*************************************************************************
	> File Name: 1.c
	> Author:Gin.TaMa 
	> Mail:1137554811@qq.com 
	> Created Time: 2018年12月22日 星期六 18时31分58秒
 ************************************************************************/
#include<stdio.h> 
int main(){ 
    int ans[400] = {0}; 
    ans[0] = ans[1] = 1; 
    for(int i = 0;i < 1000;i ++){ 
        for(int j = 1;j <= ans[0];j++){ ans[j] *= 2;
            //ans[j]<<1;
        }
        for(int j = 1;j <= ans[0];j++){
            if(ans[j] < 10)continue;
            ans[j+1] += ans[j]/10;//**//注意是 += 
            ans[j] %= 10;
            ans[0] += (ans[0] == j);
        }
            //ans[j]<<1;
    }
    int sum = 0;
    for(int i = 1;i <= ans[0];i++){
        sum += ans[i];
    }
    printf("%d\n",sum);
}
