/*************************************************************************
	> File Name: forPoint.c
	> Author:Gin.TaMa 
	> Mail:1137554811@qq.com 
	> Created Time: 2019年03月20日 星期三 09时45分06秒
 ************************************************************************/

#include<stdio.h>
int main(){
    int i = 3;
    int num[i];
    while(i --){
        num[i] = 1;
    }
    printf("aaa""bbbb""cccc\n");
    printf("%d\n",num[1]);
    char * p[] = {"A","B","C",NULL};
    for(char** t = p;*t != NULL;*t ++){
        printf("%s\n",t[0]);
    }
    return 0;
}
