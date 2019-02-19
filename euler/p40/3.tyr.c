/*************************************************************************
	> File Name: 3.tyr.c
	> Author:Gin.TaMa 
	> Mail:1137554811@qq.com 
	> Created Time: 2019年01月10日 星期四 18时56分08秒
 ************************************************************************/

#include<stdio.h>

int get_d(int n){
    if(n < 10)return n;
    n -= 10;
    int cur = 10;
    int w = 2;
    while(n > w * (cur * 10 - cur)){
        n -= w * (cur * 10 - cur);
        w ++;
        cur *= 10;
    }
    int num = n / w + cur;
    for(int i = 0;i < w - n % w - 1;i ++){
        num /= 10;
    }
    return num % 10;
}


int main(){
    int ans = 1;
    int p = 1;
    for(int i = 0;i < 7;i ++){
        ans *= get_d(p);
        p *= 10;
    }
    printf("%d\n",ans);
    return 0;
}
