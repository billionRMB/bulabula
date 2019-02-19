/*************************************************************************
	> File Name: test.c
	> Author:Gin.TaMa 
	> Mail:1137554811@qq.com 
	> Created Time: 2019年01月24日 星期四 18时43分00秒
 ************************************************************************/

#include<stdio.h>
#define max 1000
int gcd(int a,int b){
    if(b == 0)return a;
    return gcd(b,a%b);
}
int many[max + 5] = {0};
void addmany(int a,int b,int c){
}
int main(){
    for(int i = 2;i*i < max;i ++){
        for(int j = 1;j < i;j ++){
            if(gcd(j,i)!=1)continue;
            int a = i * i - j * j;
            int b = 2 * i * j;
            int c = i * i + j * j;
            if(gcd(a,b)!=1)continue;
            printf("%d:%d %d %d %d\n",i,j,a,b,c);
            addmany(a,b,c);
        }
    }
    return 0;
}
