/*************************************************************************
	> File Name: 1.c
	> Author:Gin.TaMa 
	> Mail:1137554811@qq.com 
	> Created Time: 2019年01月03日 星期四 23时15分01秒
 ************************************************************************/

#include<stdio.h>
#include <stdio.h>

int calc(int n) {
    return (2 * n * n * n + 3 * (n + 1) * n - 2 * n) / 6;
}

int main() {
    int sum1 = 0, sum2 = 0;
    sum2 = 5050;
    sum1 = calc(100);
    printf("%d\n", sum2 * sum2 - sum1);
    return 0;
}
