/*************************************************************************
	> File Name: try.c
	> Author:Gin.TaMa 
	> Mail:1137554811@qq.com 
	> Created Time: 2019年01月09日 星期三 16时48分07秒
 ************************************************************************/
#include<stdio.h>
#include<math.h>
int flag[10000] = {0};

int get_d(int x){
    return floor(log10(x)) + 1;
}

int get_a_b(int a,int b){
    return get_d(a) + get_d(b) + get_d(a * b);
}

int is_vilid(int a,int b){
    int num[10] = {0};
    num[0] = 1;
    int temp,ans;
    temp = ans = a * b;
    if(flag[ans] == -1)return 0;
    while(a){
        if(num[a % 10])return 0;
        num[a % 10] = 1;
        a /= 10;
    }
    while(b){
        if(num[b % 10])return 0;
        num[b % 10] = 1;
        b /= 10;
    }
    while(ans){
        if(num[ans % 10])return 0;
        num[ans % 10] = 1;
        ans /= 10;
    }
    flag[temp] = -1;
    return 1;
}

int main(){ 
    int sum = 0;
    for(int a = 1;get_a_b(a,a) < 10;a ++){
        for(int b = a + 1;get_a_b(a,b) < 10;b ++){
            if(get_a_b(a,b) != 9)continue;
            if(!is_vilid(a,b))continue;
            sum += a * b;
            printf("%d * %d = %d\n",a,b,a * b);
        }
    }
    printf("%d\n",sum);
    return 0;
}
