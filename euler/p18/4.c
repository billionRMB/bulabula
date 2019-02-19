/*************************************************************************
	> File Name: 1.c
	> Author:Gin.TaMa 
	> Mail:1137554811@qq.com 
	> Created Time: 2018年12月22日 星期六 19时30分42秒
 ************************************************************************/

#include<stdio.h>
#define max 15
#define MAX(a,b) ((a)>(b)?(a):(b))

//注意使用 宏定义 来实现 求最大值 好做
int map[max + 5][max + 5] = {0};

int solve(){
    for(int i = 1;i <= max;i++){
        for(int j = 0;j <= i;j++){
            // 别忘了 加上自己 ：状态转换方程 注意 还是结合一下题目实际模拟一下，才是最佳的。。。
            map[i][j] += MAX(map[i - 1][j - 1],map[i - 1][j]);
        }
    }
}
int main(){
    for(int i = 0; i< max;i ++){
        for(int j = 0;j <=i;j++){
            scanf("%d",map[i] + j);// 这种读入数组的方式，注意学习一下
        }
    }
    solve();
    int ans = 0;
    for(int i = 0;i <= max;i ++){
        ans = MAX(map[max - 1][i],ans);
    }
    printf("%d\n",ans);
    return 0;
}
