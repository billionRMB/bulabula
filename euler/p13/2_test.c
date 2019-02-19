/*************************************************************************
	> File Name: 2_test.c
	> Author:Gin.TaMa 
	> Mail:1137554811@qq.com 
	> Created Time: 2018年12月21日 星期五 17时08分36秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
void calu(int * ans,char * a,char * b){
    int len_a = strlen(a);
    int len_b = strlen(b);
    for(int i = 1;i <= len_a;i++){
        for(int j = 1;j <= len_b;j++){
            ans[i] = ans[i]*10+(a[len_a - i] - '0')*(b[j - 1] - '0');
        }
    }
    ans[0] = len_a;
    for(int i = 1;i <= len_a;i ++){
        if(ans[i] < 10) continue;
        ans[i + 1] += ans[i] / 10;
        ans[i] %= 10;
        ans[0] += (i == len_a);
    }
    while(ans[ans[0]] > 10){
        ans[ans[0]+1] = ans[ans[0]] / 10;
        ans[ans[0]] %= 10;
        ans[0] ++;
    }
}
int main(){
    char num[50];
    char num2[50];
    scanf("%s %s",num,num2);
    int ans[1000] = {0};
    calu(ans,num,num2);
    printf("%d\n",ans[0]);
    for(int i = ans[0]; i >= 1 ;i --){
        printf("%d",ans[i]);
    }
    printf("\n");
}
