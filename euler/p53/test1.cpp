/*************************************************************************
	> File Name: test1.cpp
	> Author:Gin.TaMa 
	> Mail:1137554811@qq.com 
	> Created Time: 2018年12月29日 星期六 19时27分20秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int num[105][105] = {0};
int ans = 0;
void init_num(){
    num[0][0] = 1;
    for(int i = 1;i <=100;i++){
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
    init_num();
    printf("%d\n",ans);
    return 0;
}
