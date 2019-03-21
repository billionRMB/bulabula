/*************************************************************************
	> File Name: asprintfTest.c
	> Author:Gin.TaMa 
	> Mail:1137554811@qq.com 
	> Created Time: 2019年03月20日 星期三 15时37分06秒
 ************************************************************************/

#define _GNU_SOURCE
#include<stdio.h>
#include<stdlib.h>

#define Sasprintf(p,...){\
    char* temp = (p);\
    asprintf(&p,__VA_ARGS__);\
    free(temp);\
}

int main(){
    char* m = NULL;
    Sasprintf(m,"fuck");
    printf("%s\n",m);
    return 0;
}
