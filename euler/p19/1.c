/*************************************************************************
	> File Name: 1.c
	> Author:Gin.TaMa 
	> Mail:1137554811@qq.com 
	> Created Time: 2019年01月05日 星期六 11时57分29秒
 ************************************************************************/

#include<stdio.h>
#include <inttypes.h>

int32_t WhichDay(int32_t y, int32_t m, int32_t d) {
    if (m == 1 || m == 2) {
        --y; m += 12;
    }
    int32_t w;
    w = (d + 2 * m + 3 * (m + 1) / 5 
         + y + y / 4 - y / 100 
         + y / 400) % 7;
    return w;
}

 

int32_t main() {
    int32_t sunday = 0;
    for (int32_t y = 1901; y < 2001; ++y) {
        for (int32_t m = 1; m <= 12; ++m) {
            if (WhichDay(y, m, 1) == 6)
                ++sunday;
        }
    }
    printf("%d\n", sunday);
    return 0;
}


