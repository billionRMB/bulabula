/*************************************************************************
	> File Name: 4.cpp
	> Author:Gin.TaMa 
	> Mail:1137554811@qq.com 
	> Created Time: 2019年01月02日 星期三 11时10分08秒
 ************************************************************************/
#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;
int Triangle(int n) {
    return (n * (n + 1)) / 2;
}

int Square(int n) {
    return n * n;
}

int Pentagonal(int n) {
    return n * (3 * n - 1) / 2;
}

int Hexagonal(int n) {
    return n * (2 * n - 1);
}

int Heptagonal(int n) {
    return n * (5 * n - 3) / 2;
}

int Octagonal(int n) {
    return n * (3 * n - 2);
}

int (*FuncList[6])(int)={
    Triangle,Square,Pentagonal,
    Hexagonal,Heptagonal,Octagonal
};

vector<int>g[100];

void init_graph(){
    int cnt = 0;
    for(int i = 0;i < 6;i++){
        int k = 0;
        while(FuncList[i](++k)< 1000);
        while(FuncList[i](k) < 10000){
            int num = FuncList[i](k++);
            g[num / 100].push_back(num);
            cnt++;
        }
    }
    printf("%d\n",cnt);
}

int vis[100] = {0};
int ans[6] = {0};

int binary_search(int(*fun)(int),int y){
    int head = 1,tail = y,mid , temp_mid ;
    while(head <= tail){
        mid = (head + tail)/2;
        temp_mid = fun(mid);
        if(temp_mid == y)return 1;
        if(temp_mid < y)head = mid + 1;
        else tail = mid - 1;
    }
    return 0;
}

int check(int * num){
    sort(num,num+6);
    do{
        int i;
        for(i = 0;i<6;i++){
            if(binary_search(FuncList[i],num[i]))continue;
            break;
        }
        if(i == 6)return 1;
    }while(next_permutation(num,num+6));
    return 0;
}

int dfs(int x,int d){
    ans[d - 1] = x;
    if(d == 6){
        return (ans[0]/100 == x % 100) && check(ans);
    }
    int index = x % 100;
    if(vis[index])return 0;
    for(int j = 0;j < g[index].size();j++){
        if(dfs(g[index][j],d + 1))return 1;
    }
    return 0;
}

int main(){
    init_graph();
    int flag = 1;
    for(int i = 0;i < 100&&flag;i++){
        vis[i] = 1;
        for(int j = 0;j < g[i].size()&&flag;j++){
            int num = g[i][j];
            if(dfs(num,1) == 1)flag = 0;
        }
    }
    for(int i = 0;i<6;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}
