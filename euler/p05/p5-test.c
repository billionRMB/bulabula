/*************************************************************************
	> File Name: p5-test.c
	> Author:Gin.TaMa 
	> Mail: 
	> Created Time: 2018年11月25日 星期日 15时30分18秒
 ************************************************************************/

#include<stdio.h>

int gcd(int a, int b){
    return ( b ?gcd(b , a%b) : a);
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
    printf("%d\n",gcd3(40,14));
    int ans = 1;
    for(int i = 1;i <= 20;i++){
        if(ans % i == 0)continue;
        ans = ans * i / gcd3(ans,i);
    }
    printf("%d\n",ans);
}
