/*************************************************************************
	> File Name: 2.c
	> Author:Gin.TaMa 
	> Mail:1137554811@qq.com 
	> Created Time: 2018年12月31日 星期一 10时50分11秒
 ************************************************************************/

#include<stdio.h>
#define max 200


int main(){
    int ans = 0;
    for(int a = 1;a < 100;a++){
        int num[max + 5] = {0};
        num[0] = num[1] = 1;
        for(int b = 1; b < 100;b++){
            for(int i = 1;i <= num[0]; i++){
                num[i] *= a;
            }
            for(int i = 1;i <= num[0];i++){
                if(num[i] < 10)continue;
                num[i + 1] += num[i]/10;
                num[i] %= 10;
                num[0] += (num[0] == i);
            }
            int temp = 0;
            for(int i = 1;i <= num[0] ;i++){
                temp += num[i];
            }
            ans = (ans > temp ? ans:temp);
        }
    }
    printf("%d\n",ans);
}
