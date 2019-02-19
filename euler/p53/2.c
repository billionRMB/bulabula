/*************************************************************************
	> File Name: 2.c
	> Author:Gin.TaMa 
	> Mail:1137554811@qq.com 
	> Created Time: 2018年12月30日 星期日 23时58分54秒
 ************************************************************************/

#include<stdio.h>
int ans = 0;
int num[105][105] = {0};

void init(){
    num[0][0] = 1;
    for(int i = 1;i <= 100;i ++){
        num[i][0] = 1;
        for(int j = 1;j < i;j++){
            num[i][j] = num[i - 1][j - 1] + num[i - 1][j];
            if(num[i][j] > 1000000){
                num[i][j] = 1000001;
                ans ++;
            }
        }
        num[i][i] = 1;
    }
}

int main(){
    init();
    printf("%d\n",num[5][3]);
    // 注意　ｃ５３　＝＝　ｎｕｍ[5][3]
    printf("%d\n",ans);
}
