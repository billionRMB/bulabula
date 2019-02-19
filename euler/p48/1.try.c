/*************************************************************************
	> File Name: 1.try.c
	> Author:Gin.TaMa 
	> Mail:1137554811@qq.com 
	> Created Time: 2019年01月12日 星期六 18时24分31秒
 ************************************************************************/

#include<stdio.h>

int get_n(int * num,int n){
    num[0] = 1;
    for(int i = 0;i < n;i ++){
        for(int j = 0;j <= 11;j ++){
            num[j] *= n;
        }
        for(int j = 0;j < 12;j ++){
            if(num[j] < 10)continue;
            num[j + 1] += num[j] / 10;
            num[j] %= 10;
        }
    }
}

int print(int *num){
    for(int i = 0;i < 10;i ++){
        if(num[9 - i])
        printf("%d",num[9 - i]);
    }
    printf("\n");
}

int add(int * ans,int * num){
    for(int i = 0;i <= 11;i ++){
        ans[i] += num[i];
        if(ans[i] < 10)continue;
        ans[i + 1] += ans[i] / 10;
        ans[i] %= 10;
    }
}

int main(){
    int ans[12] = {0};
    for(int i = 1;i <= 1000;i ++){
        int num[12] = {0};
        get_n(num,i);
        add(ans,num);
    }
    for(int i = 0;i < 10;i ++){
        printf("%d",ans[9-i]);
    }
    printf("\n");
    return 0;
}
