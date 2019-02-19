/*************************************************************************
	> File Name: try.c
	> Author:Gin.TaMa 
	> Mail:1137554811@qq.com 
	> Created Time: 2019年01月04日 星期五 13时03分13秒
 ************************************************************************/

#include<stdio.h>
#include<inttypes.h>
#define max 1000000
int64_t lazz[max + 5] = {0};
int get_len(int64_t i){
    if(i == 1)return 1;
    if(i < max && lazz[i])return lazz[i];
    int64_t temp;
    if(i & 1)temp = get_len(i * 3 + 1) + 1;
    else temp = get_len(i / 2) + 1;
    if(i < max)lazz[i] = temp;
    return temp;
}

int main(){
    int ans = 0,temp;
    int a = 0;
    for(int i = 1;i < max;i++){
        temp = get_len(i);
        a = (ans > temp ? a:i);
        ans = (ans > temp ? ans:temp);
    }
    printf("%d %d\n",a,ans);
}
