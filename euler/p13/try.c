/*************************************************************************
	> File Name: try.c
	> Author:Gin.TaMa 
	> Mail:1137554811@qq.com 
	> Created Time: 2019年01月04日 星期五 11时27分15秒
 ************************************************************************/

#include<stdio.h>
int ans[200] = {0};
char num[50];
int main(){
    ans[0] = 50;
    while(scanf("%s",num)!=EOF){
        for(int i = 1;i <= 50;i ++){
            ans[i] += num[50 - i] - '0'; 
        }
    }
    for(int i = 1;i < ans[0];i ++){
        if(ans[i] < 10)continue;
        ans[i + 1] += ans[i]/10;
        ans[i] %= 10;
    }
    while(ans[ans[0]] > 10){
        ans[ans[0] + 1] += ans[ans[0]] / 10;
        ans[ans[0]] %= 10;
        ans[0]++;
    }
    for(int i = 0;i < 10;i ++){
        printf("%d",ans[ans[0] - i]);
    }
    printf("\n");
    return 0;
}
