/*************************************************************************
	> File Name: ans.c
	> Author:Gin.TaMa 
	> Mail:1137554811@qq.com 
	> Created Time: 2019年01月10日 星期四 09时28分57秒
 ************************************************************************/
#include <stdio.h>
#include <inttypes.h>

#define MAX_N 1000000

int32_t reverseNum(int32_t n, int32_t base) {
    if (base <= 1) return 0;
    int32_t x = 0;
    while (n) {
        x = x * base + n % base;
        n /= base;
    }
    return x;
}

int32_t main() {
    int32_t sum = 0, base2, base10;
    for (int32_t i = 1; i <= MAX_N; i++) {
        base2 = reverseNum(i, 2);
        base10 = reverseNum(i, 10);
        if (base2 == base10 && base10 == i) sum += i;
    }
    printf("%d\n", sum);
    return 0;
}
