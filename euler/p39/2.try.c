/*************************************************************************
	> File Name: 2.try.c
	> Author:Gin.TaMa 
	> Mail:1137554811@qq.com 
	> Created Time: 2019年01月10日 星期四 16时38分55秒
 ************************************************************************/

#include<stdio.h>
#define max 1000

int gcd(int a,int b){
    if(!b)return a;
    return gcd(b,a%b);
}

int many[max + 5] = {0};

int main(){
    int a,b,c;
    for(int i = 2;i * i <  max;i++){
        for(int j = 1;j < i;j ++){
            if(gcd(i,j)!=1)continue;
            a = i * i - j * j;
            b = 2 * j * i;
            c = j * j;
            int p = a + b + c;
            for(int k = p;k < max;k += p)many[k] ++;
        }
    }
    int ans = 0;
    for(int i = 1;i <= max;i ++){
        if(many[ans] < many[i])ans = i;
    }
    printf("%d\n",ans);
    return 0;
}
