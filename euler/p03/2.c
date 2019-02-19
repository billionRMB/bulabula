/*************************************************************************
	> File Name: 2.c
	> Author:Gin.TaMa 
	> Mail:1137554811@qq.com 
	> Created Time: 2019年01月02日 星期三 21时55分11秒
 ************************************************************************/

#include<stdio.h>
#include<inttypes.h>
int main(){
    int64_t num = 600851475143,x = 2,ans = 0;
    while(num != 1){
        while(num % x != 0){
            x ++;
        }
        ans = x;
        while(num % x == 0){
            num /= x;
        }
        x ++;
    }
    printf("%"PRId64"\n",ans);
}
