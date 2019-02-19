/*************************************************************************
	> File Name: test1.c
	> Author:Gin.TaMa 
	> Mail:1137554811@qq.com 
	> Created Time: 2018年12月25日 星期二 22时23分31秒
 ************************************************************************/

#include<stdio.h>

int num(int x){
    return x * (x + 1) / 2;
}


int fac_num(int x){
    int count = 0;
    for(int i = 1;i * i < x;i ++){
        if(x % i == 0)count += 2;
    }
    return count;
}


int main(){
    int i = 1;
    while(fac_num(num(i)) < 500)i++;
    printf("%d\n",num(i));
    return 0;
}
