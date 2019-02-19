/*************************************************************************
	> File Name: test.cpp
	> Author:Gin.TaMa 
	> Mail:1137554811@qq.com 
	> Created Time: 2019年01月23日 星期三 17时25分40秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int testnum[7] = {2,3,5,7,11,13,17};
int get_val(int * num){
    if(!num[0])return 0;
    for(int i = 1;i <= 7;i ++){
        int n = 0;
        for(int j = 0;j < 3;j ++){
            n = n * 10 + num[i + j];
        }
        if(n % testnum[i - 1])return 0;
    }
    return 1;
}
int add(int * ans,int * num){
    for(int i = 0;i < 10;i ++){
        ans[i + 1] += num[9 - i];
        if(ans[i + 1] < 10)continue;
        ans[i + 2] += ans[i + 1] / 10;
        ans[i + 1] %= 10;
    }
    ans[ans[0] + 1] && (ans[0] ++);
}
void printf(int * num){
    for(int i = 0;i < 10;i ++){
        printf("%d",num[i]);
    }
    printf("\n");
}
int main(){
    int num[10] = {0};
    for(int i = 0;i < 10;i ++){
        num[i] = i;
    }
    int ans[20] = {0};
    ans[0] = 10;
    do{
        if(get_val(num)){
         add(ans,num);
            printf(num);
        } 
    }while(next_permutation(num,num + 10));
    for(int i = 0;i < ans[0];i ++){
        printf("%d",ans[ans[0] - i]);
    }
    printf("\n");
    return 0;
}
