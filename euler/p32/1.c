/*************************************************************************
	> File Name: 1.c
	> Author:Gin.TaMa 
	> Mail:1137554811@qq.com 
	> Created Time: 2018年12月21日 星期五 20时00分24秒
 ************************************************************************/

#include<stdio.h>
#include<math.h>
// 返回 x 的位数 
int digit(int x){
    return floor(log10(x)) + 1;
}
int is_digit(int,int *);
int is_digit1(int a,int b,int c){
    int num[10] = {0};
    return (is_digit(a,num) && is_digit(b,num) 
            && is_digit(c,num));
}

int is_digit(int a,int * num){
    while(a){
        if(a % 10 == 0) return 0;
        if(num[a % 10]) return 0;
        num[a % 10] = 1;
        a /= 10;
    }
    return 1;
}
int vlait[10000] = {0};
int main(){
    int ans = 0;
    for(int a = 2;digit(a)+digit(a)+digit(a * a) < 9;a ++){
        for(int b = a + 1;digit(a) + digit(b) + digit(a * b) <= 9; b ++){
            if(digit(a) + digit(b) + digit(a * b) < 9) continue;
            if(is_digit1(a,b,a * b)){
                ans += a*b * (1- vlait[a * b]);//可以少写点
                vlait[a * b] = 1;
                printf("%d * %d = %d\n",a,b,a*b);
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
