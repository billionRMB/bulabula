/*************************************************************************
	> File Name: 1.c
	> Author:Gin.TaMa 
	> Mail:1137554811@qq.com 
	> Created Time: 2019年01月05日 星期六 00时36分39秒
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

int main() {
    int64_t ans = 1, m = 20;
    for (int32_t i = 40; i > 20; --i) {
        ans *= i;
        while (ans % m == 0 && m != 1) {
            ans /= m;
            --m;
        }
    }
    printf("%"PRId64"\n", ans);
    return 0;
}


