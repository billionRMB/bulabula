/*************************************************************************
	> File Name: test.c
	> Author:Gin.TaMa 
	> Mail:1137554811@qq.com 
	> Created Time: 2019年01月24日 星期四 20时22分27秒
 ************************************************************************/

#include<stdio.h>
#define max 1000
int main(){
    for(int i = 2;i * i < max;i ++){
        for(int j = 1;j < i;j ++){
            int a = i * i - j * j;
            int b = i * j * 2;
            int c = i * i + j * j;
            int p = a + b + c;
            if(1000 % p == 0){
                int d = 1000/p;
                printf("%d %d %d\n",a * d,b * d,c * d);
                return 0;
            }
        }
    }
}
