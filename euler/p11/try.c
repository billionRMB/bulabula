/*************************************************************************
	> File Name: try.c
	> Author:Gin.TaMa 
	> Mail:1137554811@qq.com 
	> Created Time: 2019年01月04日 星期五 09时43分41秒
 ************************************************************************/

#include<stdio.h>
int num[30][30] = {0};
int dir[4][2] = {
    0,1,1,0,1,1,1,-1
};
int main(){
    for(int i = 5; i < 25;i ++){
        for(int j = 5;j < 25;j ++){
            scanf("%d",&num[i][j]);
        }
    }
    int ans = 1,temp = 1;
    for(int i = 5;i < 25;i++){
        for(int j = 5;j < 25;j++){
            for(int k = 0;k < 4;k++){
                temp = 1;
                for(int step = 0;step < 4;step ++){
                    int xx = i + step * dir[k][0];
                    int yy = j + step * dir[k][1];
                    temp *= num[xx][yy];
                }
                ans = (ans > temp ? ans : temp);
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
