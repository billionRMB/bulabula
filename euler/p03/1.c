/*************************************************************************
	> File Name: 1.c
	> Author:Gin.TaMa 
	> Mail:1137554811@qq.com 
	> Created Time: 2019年01月02日 星期三 20时58分24秒
 ************************************************************************/
#include <stdio.h>
#include <inttypes.h>

int main() {
    int64_t num = 600851475143, x = 2, ans;
    while (num != 1) {
        if (num % x) {
            x++;
            continue;
        }
        // 证明一：x 一定是一个素数
        ans = x;
        while (num % x == 0) num /= x;
        x += 1;
    }
    printf("%" PRId64 "\n", ans);
    return 0;
}
