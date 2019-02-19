/*************************************************************************
	> File Name: try.c
	> Author:Gin.TaMa 
	> Mail:1137554811@qq.com 
	> Created Time: 2019年01月08日 星期二 10时30分49秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
int num[1000 + 5] = {0};

int get_length(int n){
    memset(num,0,sizeof(num));
    int d = 10 % n;
    for(int i = 1;i <= n;i ++){
        if(d == 0)return 0;
        if(num[d])return i - num[d];
        num[d] = i;
        d = d * 10 % n;
    }
}

int main(){
    int lengh = 0,temp_lengh = 0;
    int ans = 0;
    for(int i = 2;i < 1000;i ++){
        temp_lengh = get_length(i);
        ans = temp_lengh > lengh ? i :  ans;
        lengh = temp_lengh > lengh ? temp_lengh : lengh;
    }
    printf("%d %d\n",ans,lengh);
    return 0;
}
