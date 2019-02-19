/*************************************************************************
	> File Name: 1.try.c
	> Author:Gin.TaMa 
	> Mail:1137554811@qq.com 
	> Created Time: 2019年01月12日 星期六 13时51分39秒
 ************************************************************************/
#include<iostream>
#include<algorithm>
using namespace std;

int judge[7] = {2,3,5,7,11,13,17};

int is_vaild(int * num){
    for(int i = 1;i <= 7;i ++){
        int temp = 0;
        for(int j = 0;j < 3;j ++){
            temp = temp * 10 + num[i + j];
        }
        if(temp % judge[i - 1])return 0;
    }
    return 1;
}

void add(int * ans,int * num){
    for(int i = 1;i <= 10;i++){
        ans[i] += num[10 - i];
        // 注意 num 和　ans 最低位代表的不同
        if(ans[i] < 10)continue;
        ans[i + 1] += ans[i]/10;
        ans[i] %= 10;
    } 
    ans[ans[0]+1] && ans[0] ++ ;
}

int main(){
    int num[10] = {0};
    int ans[200] = {0};
    ans[0] = 10;
    for(int i = 0;i < 10;i ++){
        num[i] = i;
    }
    do{
        if(is_vaild(num)){
            for(int i = 0;i < 10;i ++){
                printf("%d",num[i]);
            }
            printf("\n");
            add(ans,num);
        }
    }while(next_permutation(num,num + 10));
    printf("\n");
    for(int i = ans[0];i >= 1;i--){
        printf("%d",ans[i]);
    }
    printf("\n");
    return 0;
}
