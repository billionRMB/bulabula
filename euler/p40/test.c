/*************************************************************************
	> File Name: test.c
	> Author:Gin.TaMa 
	> Mail:1137554811@qq.com 
	> Created Time: 2019年01月23日 星期三 20时36分21秒
 ************************************************************************/

#include<stdio.h>

int get_d(int n){
    if(n < 10)return n; 
    n -= 10;
    int w = 2;
    int begine = 10;
    while(n  - (w)*(10 * begine - begine) > 0){
        n -= w* (10 * begine - begine);
        w ++;
        begine *= 10;
    }
    int num = n / w + begine;
    int d = n % w;
    for(int i = 0;i <w - d - 1;i ++){
        num /= 10;
    }
    return num % 10;
}

int main(){
    int temp = 1;
    for(int i = 1;i <= 7;i ++){
        printf("%d\n",get_d(temp));
        temp *= 10;
    }
    return 0;
}
