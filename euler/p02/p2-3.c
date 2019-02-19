/*************************************************************************
	> File Name: p2-2.c
	> Author: 
	> Mail: 
	> Created Time: 2018年11月17日 星期六 15时19分37秒
 ************************************************************************/

#include<stdio.h>

#define MAX_N 4000000

int main(){
    int fib[2];
    fib[0] = 1;
    fib[1] = 1;
    int n = 2,ans = 0;
    while (fib[(n - 1) % 2] <= MAX_N){
        if(fib[(n -1) % 2] % 2 == 0) ans += fib[(n-1)%2];
        fib[n%2] += fib[(n-1)%2];
        n ++;
    }
    printf("%d\n",ans);
    return 0;
}
