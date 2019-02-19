/*************************************************************************
	> File Name: try.c
	> Author:Gin.TaMa 
	> Mail:1137554811@qq.com 
	> Created Time: 2019年01月03日 星期四 23时53分14秒
 ************************************************************************/

#include<stdio.h>
#include<inttypes.h>
#define l_n 13
int num[1005] = {0};

int main(){
    int i = -1;
    char a;
    while(scanf("%c",&a)!=EOF){
        if(a == '\n')continue;
        num[++i] = a - '0';
    };
    int64_t temp = 1,ans = 1;
    int l = 0;
    for(i = 0;i < 1000;i ++){
        if(num[i] == 0){
            l = 0;
            temp = 1;
            continue;
        }
        temp *= num[i];
        if(l != l_n){
            l ++;
        }else{
            temp /= num[i - 13];
        }
        ans = (ans < temp ? temp : ans );
    }
    printf("%"PRId64"\n",ans);
    return 0;
}
