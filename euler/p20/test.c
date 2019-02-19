/*************************************************************************
	> File Name: test.c
	> Author:Gin.TaMa 
	> Mail:1137554811@qq.com 
	> Created Time: 2019年01月25日 星期五 16时39分05秒
 ************************************************************************/

#include<stdio.h>
int num[200] = {0};
void pn(int * num){
    for(int i = 0;i < num[0];i ++){
        printf("%d",num[num[0] - i]);
    }
    printf("\n");
}
int main(){
    num[0] = 1;
    num[1] = 1;
    for(int j = 1;j <= 100;j ++){
        for(int i = 1;i <= num[0];i ++){
            num[i] *= j;
        } 
        for(int i = 1;i <= num[0];i ++){
            if(num[i] < 10)continue;
            num[i + 1] += num[i] / 10;
            num[i] %= 10;
            num[0]+=(num[0] == i);
        }
        pn(num);
    }
    int sum = 0;
    for(int i = 1;i <= num[0];i ++){
        sum += num[i];
    }
    printf("%d\n",sum);
    return 0;
}
