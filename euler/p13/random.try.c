/*************************************************************************
	> File Name: random.try.c
	> Author:Gin.TaMa 
	> Mail:1137554811@qq.com 
	> Created Time: 2019年01月13日 星期日 19时43分48秒
 ************************************************************************/

#include<stdio.h>

int add(int * ans,char * num){
    for(int i = 1;i <= 50;i ++){
        ans[i] += num[50 - i] - '0';
    }
    // 循环的时候一定要老老实实的考虑循环的初始条件
    for(int i = 1;i <= ans[0];i ++){
        if(ans[i] < 10)continue;
        ans[i + 1] += ans[i] / 10;
        ans[i] %= 10;
    }
    ans[ans[0] + 1] && ans[0]++;
}

int main(){
    int ans[55] = {0};
    ans[0] = 50;
    char num[55];
    while(~scanf("%s",num)){
        add(ans,num);
    }
    for(int i = 0;i < 10;i ++){
        printf("%d",ans[ans[0] - i]);
    }
    printf("\n");
    return 0;
}
