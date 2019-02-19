/*************************************************************************
	> File Name: p11.c
	> Author:Gin.TaMa 
	> Mail: 
	> Created Time: 2018年11月24日 星期六 19时16分54秒
 ************************************************************************/

#include<stdio.h>

int dir[4][2]={
    0 , 1, 1, 1,1 ,0,1,-1
};

int main(){
    int num[30][30] = {0};
    //重定向
    for(int i = 5; i < 25;i++){
        for(int j = 5;j < 25;j++){
            scanf("%d", &num[i][j]);
        }
    }    
    int ans = 0;
    for(int x = 5 ; x < 25;x++){
        for(int y = 5; y < 25;y++){
            for(int k = 0;k < 4;k ++){
                int p = 1;
                for(int step = 0; step < 4; step ++){
                    int xx = x + step * dir[k][0];
                    int yy = y + step * dir[k][1];//第二个位置代表了是x还是y
                    p *= num[xx][yy];
                }
              //  ans = p ? p > ans : ans;
                if(p > ans) ans = p;
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
