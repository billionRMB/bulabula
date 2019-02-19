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
    while(x  <= num){
        if(num % x ){
            x++;
            continue;
        }
        //证明 1 ： x 一定是一个 质数
        //想象一个数组list储存着每一个执行至此的x的值
        //那么 假设此时的x为 list里第 n 个 为 合数 a * b（a <= b)
        //那么 a 必定为 num的一个因子
        //考虑 list里n - 1 的值 假设为 c的话那么 下一个 因子 必定为 a
        //又因为 a ！= a * b 所以 假设不成立
       // ans = x;
        while(num % x == 0) num /= x;
        ans = x;
        x += 1;
    }
    //if(num - 1 ) ans = num ; // 证明 2 ：这行代码是必要的 当然了 因为x的范围为 0 到 根号下num 但是 x的范围应该为 0 到 num 
    printf("%" PRId64 "\n", ans);
    return 0;
}
