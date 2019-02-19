/*************************************************************************
	> File Name: ans.cpp
	> Author:Gin.TaMa 
	> Mail:1137554811@qq.com 
	> Created Time: 2019年01月12日 星期六 17时10分04秒
 ************************************************************************/
#include <stdio.h>

#include <inttypes.h>

 

#define MAX_N 10000

 

int32_t a[MAX_N + 5] = {0};

int32_t prime[MAX_N] = {0};

 

int32_t main() {

    for (int32_t i = 2; i <= MAX_N; i++) {

        if (!prime[i]) { prime[++prime[0]] = i; a[i] = 1; }

        for (int32_t j = 1; j <= prime[0]; j++) {

            if (i * prime[j] > MAX_N) break;

            prime[i * prime[j]] = 1;

            if (i % prime[j] == 0) break;

        }

    }

    for (int32_t i = 1; i <= prime[0]; i++) {

        for (int32_t n = 1; true; n++) {

            if (prime[i] + 2 * n * n > MAX_N) break;

            a[prime[i] + 2 * n * n] = 1;

        }

    }

    for (int32_t i = 9; i <= MAX_N; i += 2){

        if (a[i]) continue;

        printf("%d\n", i);

        break;

    }

    return 0;

}

