/*************************************************************************
	> File Name: 1.c
	> Author:Gin.TaMa 
	> Mail:1137554811@qq.com 
	> Created Time: 2019年01月08日 星期二 11时52分13秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define test_round 30
#define max_n 10000

int prime[max_n + 5] = {0};

int gcd(int a,int b){
    if(!b)return a;
    return gcd(b,a % b);
}

int r_m_test(int x){
    if(x <= 1)return 0;// 注意对函数的输入范围进行限制，这才是一个良好的定义函数的方式
    int a , m, ans ;
    for(int i = 0;i < test_round;i ++){
        a = rand()%(x - 1) + 1;
        m = x - 1;
        ans = 1;// ans = 1;
        while(m){
            if(m & 1)ans = ans * a % x;
            a = a * a % x;
            m >>= 1;
        }
        if(ans != 1)return 0;
    }
    return 1;
}

int get_leng(int a,int b){
    int i = 0;
    while(r_m_test(i * i + a * i + b))i ++;
    return i;
}

void init(){
    for(int i = 2;i < max_n;i ++){
        if(!prime[i])
            for(int j = i;j < max_n;j += i)
                (!prime[j])&&(prime[j] = i);
    }
}

int main(){
    srand(time(0));
    init();
    int ans = 0,temp_l = 0,max_l = 0;
    for(int a = -999;a < 1000;a ++){
        for(int b = 2;b < 1000;b ++){
            if(prime[b] != b)continue;
            if(prime[a + b + 1]!= a + b + 1)continue;
            if(a > 0 && b > 0 && prime[gcd(a,b)] <= max_l)continue;
            temp_l = get_leng(a,b);
            if(temp_l > max_l){
                ans = a * b;
                max_l = temp_l;
            }
        }
    }
    printf("%d\n",ans); 
    return 0;
}
