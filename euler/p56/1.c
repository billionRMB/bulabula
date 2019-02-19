/*************************************************************************
	> File Name: test1.cpp
	> Author:Gin.TaMa 
	> Mail:1137554811@qq.com 
	> Created Time: 2018年12月29日 星期六 19时48分11秒
 ************************************************************************/
#include<stdio.h>
#include<string.h>
#define max 300

int ans[max + 5] = {0};

int calc(int a,int b){
    memset(ans,0,sizeof(int) * (max + 5));
    ans[0] = ans[1] = 1;
    for(int i = 0;i < b;i++){
        for(int i = 1;i <= ans[0];i++){
            ans[i] *= a;
        }
        for(int i = 1;i <= ans[0];i++){
            if(ans[i] < 10)continue;
            ans[i + 1] += ans[i] / 10;
            ans[i] %= 10;
            ans[0] += (ans[0] == i);
        }
    }
}

int main(){
    int sum = 0;
    for(int i = 2;i < 100;i ++){
        for(int j = 1;j < 100;j ++){
            calc(i,j);
            int temp_sum = 0;
            for(int i = 1;i <= ans[0];i++){
                temp_sum += ans[i];
            }
            sum = (sum > temp_sum ? sum:temp_sum);
        }
    }
    printf("%d\n",sum);
    return 0;
}
