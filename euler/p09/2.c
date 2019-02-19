/*************************************************************************
	> File Name: 1.try.c
	> Author:Gin.TaMa 
	> Mail:1137554811@qq.com 
	> Created Time: 2019年01月04日 星期五 08时28分01秒
 ************************************************************************/
 #include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int flag = 1;
    int32_t a, b, c, e;
    for (int32_t i = 1; i < 32 && flag; ++i) {
        for (int32_t j = i + 1; j <= 32 && flag; ++j) {
            a = j * j - i * i;
            b = 2 * i * j;
            c = i * i + j * j;
            if (1000 % (a + b + c) == 0) {
                e = (int32_t)pow(1000 / (a + b + c), 3);
                printf("%d\n", e * a * b * c);
                flag = 0; 
            }
        }
    }
    return 0;
}
