/*************************************************************************
	> File Name: try.c
	> Author:Gin.TaMa 
	> Mail:1137554811@qq.com 
	> Created Time: 2019年01月03日 星期四 17时58分04秒
 ************************************************************************/

#include<stdio.h>

int is_vaild(int x){
    int num = 0,temp = x;
    while(x){
        num = num * 10 + x % 10;
        x /= 10;
    }
    return temp == num;
}


int main(){
    int ans = 0;
    for(int a = 100; a < 1000;a ++){
        for(int b = a ;b < 1000;b++){
            if(is_vaild(a * b)){
                printf("%d * %d = %d\n",a,b,a*b);
                ans = ans > a * b ? ans : a * b;
            }
        }
    }
    printf("%d\n",ans);
}
