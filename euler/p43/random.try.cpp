/*************************************************************************
	> File Name: random.try.cpp
	> Author:Gin.TaMa 
	> Mail:1137554811@qq.com 
	> Created Time: 2019年01月18日 星期五 22时40分09秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int ans[10] = {0};
int sum[20] = {0};
int is_valid(int * num){
    static int test[7] = {2,3,5,7,11,13,17}; 
    for(int i = 1;i < 8;i ++){
        int sum = 0;
        for(int j = 0;j < 3;j ++){
            sum = sum * 10 + num[i + j];
        }
        if(sum % test[i - 1])return 0;
    }
    // 一定要对初始每一个条件的初始条件进行检查
    return 1;
}

int add(int * num,int * ans){
    for(int i = 0;i < 10;i ++){
        ans[i + 1] += num[9 - i];
    }
    for(int i = 1;i < ans[0];i ++){
        if(ans[i] < 10)continue;
        ans[i + 1] += ans[i] / 10;
        ans[i] %= 10;
        ans[0] += (i == ans[0]);
    }
}

int main(){
    sum[0] = 10;
    for(int i = 0;i < 10;i ++){
        ans[i] = i;
    }
    do{
        if(is_valid(ans)){
            for(int i = 0;i < 10;i ++){
                printf("%d",ans[i]);
            }
            printf("\n");
         add(ans,sum);    
        }
    }while(next_permutation(ans,ans + 10));
    // 注意全排列是数组名，数组名＋数组长度
    for(int i = sum[0];i > 0;i --){
        printf("%d",sum[i]);
    }
    printf("\n");
    return 0;
}
