/*************************************************************************
	> File Name: random.try.c
	> Author:Gin.TaMa 
	> Mail:1137554811@qq.com 
	> Created Time: 2019年01月17日 星期四 20时43分43秒
 ************************************************************************/

#include<stdio.h>

void get_n(int * num,int i){
    num[0] = 1;
    for(int n = 0;n < i;n ++){
        for(int n = 0;n < 10;n ++ ){
            num[n] *= i;
        }
        for(int n = 0;n < 10;n ++){
            if(num[n] < 10)continue;
            num[n + 1] += num[n] / 10;
            num[n] %= 10;
        }
    }
}

void get_ans(int * num,int * ans){
    for(int i = 0;i < 10;i ++){
        ans[i] += num[i];
        if(ans[i]<10)continue;
        ans[i + 1] += ans[i] /10;
        ans[i] %= 10;
    }
}
int print(int *num){
    for(int i = 0;i < 10;i ++){
        if(num[9 - i])
        printf("%d",num[9 - i]);
    }
    printf("\n");
}

int main(){
    int ans[12] = {0};
    for(int i = 1;i <= 1000;i ++){
        int num[12] = {0};
        get_n(num,i);
        get_ans(num,ans);
    }
    for(int i = 9;i >= 0;i --)
    printf("%d",ans[i]);
    printf("\n");
    return 0;
}
