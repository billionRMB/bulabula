/*************************************************************************
	> File Name: 1.c
	> Author:Gin.TaMa 
	> Mail:1137554811@qq.com 
	> Created Time: 2018年12月29日 星期六 17时28分31秒
 ************************************************************************/
#include<iostream>
#include<stack>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <stack>

using namespace std;
#define max 10000

int vis[max + 5] = {0};

double calc(char * result,int n){
    stack<double> s;
    for(int i = 0;i < n;i ++){
        if(result[i] <= '9' && result[i] >= '0'){
            s.push(result[i] - '0');
            continue;
        }
        double a = s.top();s.pop();
        double b = s.top();s.pop();
        switch(result[i]){
            case '+':s.push(a + b);break;
            case '-':s.push(b - a);break;
            case '*':s.push(a * b);break;
            case '/':s.push(b / a);break;
        }
    }
    return s.top();
}

#define ESP 1e-7
// 用来判断　是否为整数
int dfs(char *result,int k,int a,int b,int * num){
    if(k == 7){
        double ret = calc(result,7);
        if(ret > 0 && fabs(ret - floor(ret)) < ESP){
            vis[(int)ret] = 1; 
        }
        return 1;
    }
    if( b + 1 < a ){
        result[k] = '+',dfs(result,k + 1,a,b+1,num);
        result[k] = '-',dfs(result,k + 1,a,b+1,num);
        result[k] = '*',dfs(result,k + 1,a,b+1,num);
        result[k] = '/',dfs(result,k + 1,a,b+1,num);
    }
    if( a < 4 ){
        result[k] = num[a] + '0';
        dfs(result,k + 1, a + 1,b,num);
    }
    return 0;
}

int len = 0,ret = 0;

void dfs2(int * num,int k){
    if(k == 4){
        char result[7] = {0};
        memset(vis,0,sizeof(vis));
        do{
            dfs(result,0,0,0,num);
        }while(next_permutation(num,num + 4));
        int temp_len = 1;
        for(;vis[temp_len];temp_len++);
        if(temp_len - 1 > len){
            len = temp_len;
            ret = num[0] * 1000 + num[1] * 100 + num[2]
                        * 10 + num[3];
        }
        return ;
    }
    int begin = (k == 0 ? 1 :num[k - 1] + 1);
    // 可以多使用一个变量，避免一个语句变量过长
    for(int i = begin;i <= 9; i++){
        num[k] = i;
        dfs2(num,k + 1);
    }
    return ;
}


int main(){
    int num[4];
    dfs2(num,0);
    cout<<ret<<endl;
    return 0;
}
