/*************************************************************************
	> File Name: 1.c
	> Author:Gin.TaMa 
	> Mail:1137554811@qq.com 
	> Created Time: 2018年12月22日 星期六 14时16分22秒
 ************************************************************************/

#include<stdio.h>
//暴力枚举
int num(int x){
    return x * ( x + 1 )/2;
}

int fac_num(int x){
    int count = 0;
    for(int i = 1;i*i <= x;i ++){
        if(x % i == 0){
            count += 2;
            //x /= i;
        }
    }
    return count;
}


int main(){
    int n = 1;
    while(fac_num(num(n))<500){
        n ++;
    }
    printf("%d\n",num(n));
    return 0;
}
