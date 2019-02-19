/*************************************************************************
	> File Name: try.c
	> Author:Gin.TaMa 
	> Mail:1137554811@qq.com 
	> Created Time: 2019年01月05日 星期六 12时00分34秒
 ************************************************************************/

#include<stdio.h>
#define max 400
int ans[max] = {0};

void init(){
    ans[0] = ans [1] = 1;
    for(int x = 1; x <= 100;x++){
        for(int i = 1;i <= ans[0];i++){
            ans[i] *= x;
        }
        for(int i = 1;i <= ans[0];i++){
            if(ans[i] < 10) continue;
            ans[i + 1] += ans[i] / 10;
            ans[i] %= 10;
            ans[0] += (ans[0] == i);
        }
    }
}

int main(){
    init();
    int sum = 0;
    for(int i = 1;i <= ans[0];i ++){
        sum += ans[i];
    }
    printf("%d\n",sum);
    return 0;
}
