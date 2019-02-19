/*************************************************************************
	> File Name: 1.c
	> Author:Gin.TaMa 
	> Mail:1137554811@qq.com 
	> Created Time: 2019年01月08日 星期二 19时44分32秒
 ************************************************************************/

#include<stdio.h>

int get_sum(int i){
    return i*i * 4 - 6 * (i - 1);  
}

int main(){
    int sum = 0;
    for(int i = 3;i <= 1001 ;i += 2){
        sum += get_sum(i);
    }
    printf("%d\n",sum + 1);
    return 0;
}
