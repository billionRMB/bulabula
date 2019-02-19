/*************************************************************************
	> File Name: 2.c
	> Author:Gin.TaMa 
	> Mail:1137554811@qq.com 
	> Created Time: 2019年01月08日 星期二 17时59分48秒
 ************************************************************************/
#include<time.h>
#include<stdio.h>
#include<stdlib.h>

#define max_n 10000
#define test_round 30

int prime[max_n + 5] = {0};

int gcd(int a,int b){
    if(!b)return a;
    return gcd(b,a%b);
}

int r_m_test(int x){
    if(x <= 1)return 0;
    int a ,m,ans ;
    for(int i = 0;i < test_round ;i++){
        a = (rand()%(x - 1))+1;
        ans = 1;
        m = x - 1;
        while(m){
            if(m & 1)ans = (ans * a) % x;
            a = (a * a) % x;
            m >>= 1;
        }
        if(ans != 1)return 0;
    }
    return 1;
}

int get_lengh(int a,int b){
    int i = 0;
    while(r_m_test(i * i + a * i + b))++i;
    return i;
}


int main(){
    srand(time(0));
    
    for(int i = 2;i < max_n;i ++){
        if(!prime[i]){
            for(int j = i;j < max_n;j += i){
                if(!prime[j]) prime[j] = i;
            }
        }
    }
    
    int ans = 0,max_lengh = 40,temp_lengh = 0;
    for(int a = -999;a < 1000;a ++){
        for(int b = 2;b < 1000;b ++ ){
            if(prime[b] != b)continue;
            if(prime[b + a + 1] != a + b + 1)continue;
            if(a > 0 && b > 0 && prime[gcd(a,b)] <= max_lengh)continue;
            temp_lengh = get_lengh(a,b);
            if(temp_lengh > max_lengh){
                max_lengh = temp_lengh;
                ans = a * b;
            }
        }
    }

    printf("%d\n",ans);
    return 0;
}
