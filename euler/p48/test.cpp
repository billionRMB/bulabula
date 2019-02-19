/*************************************************************************
	> File Name: test.cpp
	> Author:Gin.TaMa 
	> Mail:1137554811@qq.com 
	> Created Time: 2019年01月23日 星期三 14时14分30秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
void printf(int * num){
    for(int i = 0;i < 10;i ++){
        printf("%d",num[9 - i]);
    }
    printf("\n");
}
void get_num(int x,int* num){
    num[0] = 1;
    for(int j = 0;j < x;j ++){
        for(int j = 0;j < 10;j ++){
           num[j] *= x; 
        }
        for(int i = 0;i < 10;i ++){
            if(num[i] < 10)continue;
            num[i + 1] += num[i] / 10;
            num[i] %= 10;
        }
    }
}
void add(int * num,int * ans){
    for(int i = 0;i < 10;i ++){
        ans[i] += num[i];
        if(ans[i] < 10)continue;
        ans[i + 1] += ans[i]/10;
        ans[i] %= 10;
    }
}
int main(){
    int ans[12] ={0};
    for(int i = 1;i <=1000;i ++){
        int num[12] = {0};
        get_num(i,num);
        add(num,ans); 
    }
    printf(ans);
    return 0;
}
