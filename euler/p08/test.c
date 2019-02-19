/*************************************************************************
	> File Name: test.c
	> Author:Gin.TaMa 
	> Mail:1137554811@qq.com 
	> Created Time: 2019年01月25日 星期五 14时56分04秒
 ************************************************************************/

#include<stdio.h>
#include<inttypes.h>
int num[1005] = {0};
int main(){
    int i = 0;
    char a;
    while(~scanf("%c",&a)){
        if(a == '\n')continue;
        num[i++] = a - '0';
    }
    int len = 0;
    int64_t ans = 1,temp = 1;
    for(int i = 0;i < 1000;i ++){
        if(num[i] == 0){
            len = 0;
            temp = 1;
            i ++;
        }
        if(len < 13){
            temp *= num[i];
            len ++;
        }else{
            temp = temp * num[i]/num[i - 13];
        }
        if(temp > ans)ans = temp; 
    }
    printf("%"PRId64"\n",ans);
    return 0;
}
