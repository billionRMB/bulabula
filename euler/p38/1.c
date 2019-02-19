/*************************************************************************
	> File Name: 1.c
	> Author:Gin.TaMa 
	> Mail:1137554811@qq.com 
	> Created Time: 2018年12月21日 星期五 20时45分32秒
 ************************************************************************/

#include<stdio.h>
#include<math.h>
int get_digit(int a,int * num,int * i){
    while(a){
        if(a % 10 == 0)return 0;
        if(num[a %10])return 0;
        num[a % 10] = 1;
        a /= 10;
        *i += 1;
    }
    return 1;
}

int is_digit(int x){
    int num[10] = {0};
    int n = 0, digit = 0;
    do{
        n += 1;
        int y = x * n;
        if(!get_digit(y,num,&digit))return 0;
    }while(digit < 9);
    if(digit > 9) return 0;
    int ret = 0;
    for(int i = 1; i <= n;i ++){
        int y = i * x;
        ret = ret * (int)pow(10,floor(log10(y))+1) + y;
    }
    return ret;
}

int main(){
    int ans = 0;
    for(int i = 1;i < 10000;i ++){
        int temp = is_digit(i);
        temp && printf("%d * (1,2,3 ....) = %d\n",i,temp);
        ans = temp > ans  ? temp : ans;
    }
    printf("%d\n",ans);
    return 0;
}
