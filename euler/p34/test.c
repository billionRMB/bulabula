/*************************************************************************
	> File Name: test.c
	> Author:Gin.TaMa 
	> Mail:1137554811@qq.com 
	> Created Time: 2019年01月25日 星期五 14时48分47秒
 ************************************************************************/

#include<stdio.h>
#define max 3000000 
int num[10] = {0};

void init(){
    num[0] = 1;
    for(int i = 1;i < 10;i ++){
        num[i] = num[i - 1] * i;
    }
}

int is_vaild(int i){
    int sum = 0;
    int temp = i;
    while(i){
        sum += num[i % 10];
        i /= 10;
    }
    return sum == temp;
}

int main(){
    init();
    long long int sum = 0;
    for(int i = 10;i < max;i ++){
        if(is_vaild(i))sum += i;
    }
    printf("%lld\n",sum);
    return 0;
}
