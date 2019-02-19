/*************************************************************************
	> File Name: p5-1.c
	> Author:Gin.TaMa 
	> Mail: 
	> Created Time: 2018年11月24日 星期六 09时48分04秒
 ************************************************************************/

#include<stdio.h>

int gcd(int a, int b){
    if(!b) return a;
    return gcd(b,a % b);
}
int gcd1(int a,int b){
    return (b ? gcd(b,a%b):a);
}
int gcd2(int a, int b){
    while(b){
        a = a % b;
        b ^= a;
        a ^= b;
        b ^= a;
    }
    return a;
}

int gcd3(int a,int b){
    int n = 1;
    int num[2];
    num[0] = a;
    num[1] = b;
    while(num[n % 2]){
        num[(n - 1)%2] %= num[n % 2];
        n++;
    }
    return num[(n - 1)%2];
}

int main(){
    int ans = 1 ;
    for(int i = 1;i <= 20 ;i++){
        if(ans % i == 0)continue;
        ans = i * ans / gcd1(ans,i);
    }
    printf("%d\n" , ans);
    return 0;
}
