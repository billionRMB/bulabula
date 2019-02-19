/*************************************************************************
	> File Name: test.c
	> Author:Gin.TaMa 
	> Mail:1137554811@qq.com 
	> Created Time: 2019年01月25日 星期五 15时32分27秒
 ************************************************************************/

#include<stdio.h>
int num[2][2000] = {0};
void add(int * a,int * b){
    //注意　最大的那个
    a[0] = b[0] > a[0] ? b[0] : a[0];
    for(int i = 1;i <= a[0];i ++){
        a[i] = a[i] + b[i];
        if(a[i] < 10)continue;
        a[i + 1] += a[i] / 10;
        a[i] %= 10;
    }
    a[a[0] + 1] && a[0] ++;
}
void print(int* num){
    for(int i = 0;i < num[0];i ++){
        printf("%d",num[num[0] - i]);
    }
    printf("\n");
}

int main(){
    num[0][0] = num[1][0] = 1;
    num[1][1] = num[1][1] = 1;
    int i = 1;
    while(num[i % 2][0] < 1000){
        //printf("%d ",i);print(num[i%2]);
        i++;
        add(num[i % 2],num[(i - 1)%2]);
    }
    printf("%d\n",i);
    return 0;
}
