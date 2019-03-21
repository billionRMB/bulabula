/*************************************************************************
	> File Name: strtorkTest.c
	> Author:Gin.TaMa 
	> Mail:1137554811@qq.com 
	> Created Time: 2019年03月20日 星期三 16时00分49秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
int main(){
    char str[] = "123:456:789";
    char*c;
    char* a = strtok_r(str,":",&c);
    do{
        printf("a:%s\n",a);
        printf("c:%s\n",c);
    }
    while((a = strtok_r(NULL,":",&c))!=NULL);
    return 0;
}
