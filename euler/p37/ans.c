/*************************************************************************
	> File Name: ans.c
	> Author:Gin.TaMa 
	> Mail:1137554811@qq.com 
	> Created Time: 2019年01月10日 星期四 10时59分01秒
 ************************************************************************/
#include <stdio.h>
#include <inttypes.h>
#include <math.h>
#define MAX_RANGE 50000000
#define MAX_N 1000000


int32_t isPrime[MAX_RANGE+ 5] = {0};
int32_t prime[MAX_RANGE+ 5] = {0};
 

void initPrime() {
    isPrime[0] = isPrime[1] = 1;
    for (int32_t i = 2; i <= MAX_RANGE; i++) {
        if (!isPrime[i]) {prime[++prime[0]] = i;}
        for (int32_t j = 1; j <= prime[0]; j++) {
            if (prime[j] * i >= MAX_RANGE) break;
            isPrime[prime[j] * i] = 1;
            if (i % prime[j] == 0) break;
        }
    }
}

bool isCircularPrime(int32_t n) {
    if (isPrime[n] != 0) return false;
    int32_t x = n, h;
    while (x) {
        if (isPrime[x] != 0) return false;
        x /= 10;
    }
    h = (int32_t)pow(10, floor(log10(n)));
    x = n;
    while (x) {
        if (isPrime[x] != 0) return false;
        x -= (x / h) * h;
        h /= 10;
    }
    return true;
}

int32_t solve() {
    int32_t many = 0, flag = 11;
    for (int32_t i = 1; i <= prime[0]; i++) {
        if (prime[i] < 10) continue;
        if (!isCircularPrime(prime[i])) continue;
        many += prime[i];
        if (!(--flag)) break;
    }
    return many;
}

int32_t main() {
    initPrime();
    int32_t many = solve();
    printf("%d\n", many);
    return 0;
}


