/*************************************************************************
	> File Name: p3-1.c
	> Author: 
	> Mail: 
	> Created Time: 2018年11月17日 星期六 16时30分57秒
 ************************************************************************/

#include<stdio.h>
#include<inttypes.h>

int main(){
    int64_t num = 600851475143,x = 2 , ans  ;
    while(x * x <= num){
        if(num % x ){
            x++;
            continue;
        }
        //证明 1 ： x 一定是一个 质数
        ans = x;
        while(num % x == 0) num /= x;
        x += 1;
    }
    if(num - 1 ) ans = num ; // 证明 2 ：这行代码是必要的
    printf("%" PRId64 "\n", ans);
    return 0;
}
