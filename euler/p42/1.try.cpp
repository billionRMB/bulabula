/*************************************************************************
	> File Name: 1.try.c
	> Author:Gin.TaMa 
	> Mail:1137554811@qq.com 
	> Created Time: 2019年01月11日 星期五 20时40分53秒
 ************************************************************************/
#include<iostream>
#include<algorithm>
using namespace std;

int is_vaild(int * num){

}

int add(int * ans,int * num){
    
}

int main(){
    int num[10] = {0};
    int ans[100] = {0};
    for(int i = 1;i < 11;i ++)
        num[i] = i;

    do{
        if(is_vaild(num))add(ans,num);
    }while(next_permutation(num,num + 10));
    return 0;
}
