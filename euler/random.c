/*************************************************************************
	> File Name: random.c
	> Author:Gin.TaMa 
	> Mail:1137554811@qq.com 
	> Created Time: 2019年01月14日 星期一 09时00分05秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int get_n(char * str){
    int n = 0;
    for(int i = 0;str[i];i ++){
        n =  n * 10 + str[i]-'0';
    }
    return n;
}

int main(int argc,char * argv[]){
    srand(time(0));
    int n = 0;
    if(argc >= 2){
        n = get_n(argv[1]);
    }
    printf("生成1 －%d以内的随机数\n",n);
    printf("%d\n",rand()%n + 1);
    return 0;
}
