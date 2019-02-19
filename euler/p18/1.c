/*************************************************************************
	> File Name: 1.c
	> Author:Gin.TaMa 
	> Mail:1137554811@qq.com 
	> Created Time: 2018年12月22日 星期六 19时30分42秒
 ************************************************************************/

#include<stdio.h>
#define max 15

int map[max + 5][max + 5] = {0};

int solve(int i,int j){
    if(i == max) return 0;
    int lnum = solve(i + 1,j),rnum = solve(i + 1,j + 1);
    return map[i][j] + (lnum > rnum ? lnum :rnum);
}
int main(){
    for(int i = 0; i< max;i ++){
        for(int j = 0;j <=i;j++){
            scanf("%d",map[i] + j);
        }
    }
    printf("%d\n",solve(0,0));
    return 0;
}
