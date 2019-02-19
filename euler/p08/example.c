/*************************************************************************
	> File Name: example.c
	> Author:Gin.TaMa 
	> Mail:1137554811@qq.com 
	> Created Time: 2019年01月03日 星期四 23时43分41秒
 ************************************************************************/

#include <stdio.h>

#include <stdlib.h>

#include <inttypes.h>



int main() {

    int64_t ans = 1, zero = 0, maxN = 0;

    for (int32_t i = 0; i < 1000; ++i) {

        if (a[i] != '0') {

            ans *= a[i] - '0';

        } else {

            ++zero;

        }

        if (i >= 13) {

            if (a[i - 13] != '0') {

                ans /= a[i - 13] - '0';

            } else {

                --zero;

            }

        }

        if (zero == 0 && ans > maxN) maxN = ans;

    }

    printf("%"PRId64"\n",maxN);

    return 0;

}
