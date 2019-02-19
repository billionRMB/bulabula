/*************************************************************************
	> File Name: random.try.c
	> Author:Gin.TaMa 
	> Mail:1137554811@qq.com 
	> Created Time: 2019年01月22日 星期二 13时13分03秒
 ************************************************************************/

#include<stdio.h>
#include<math.h>
int getW(int n){
    if(n < 10)return n;
    n -= 10;
    int cur = 10;
    int w = 2;
    while(n > w * (cur * 10 - cur)){
        n -= w * (cur * 10 -cur);
        w ++;cur *= 10;
    }
    int num = n / w + cur;
    for(int i = 0;i < w - n % w - 1;i ++)num /= 10;
    return num % 10;
}
int main(){
    int temp = 1;
    int ans = 1;
    for(int i = 1;i <= 7;i ++){
        printf("%d\n",getW(temp));
        temp *= 10;
    }
    printf("%d\n",ans);
    return 0;
}
