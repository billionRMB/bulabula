/*************************************************************************
	> File Name: 1.try.c
	> Author:Gin.TaMa 
	> Mail:1137554811@qq.com 
	> CreatePRId64 Time: 2019年01月04日 星期五 08时28分01秒
 ************************************************************************/

#include<stdio.h>
#include<inttypes.h>
int main(){
    int64_t a,b,c = 0;
    int flag = 1;
    for(a = 1;a < 334 && flag;a ++){
        for(b = a; b < 1000 - a && flag; b++){
            c = 1000 - a - b;
            if(c * c == a * a + b * b ){
                flag = 0;
                printf("%"PRId64"\n",a*b*c);
            }
        }
    }
}
