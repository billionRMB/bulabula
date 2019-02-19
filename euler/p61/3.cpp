/*************************************************************************
	> File Name: 3.cpp
	> Author:Gin.TaMa 
	> Mail:1137554811@qq.com 
	> Created Time: 2019年01月01日 星期二 23时47分36秒
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

vector<int> g[100];
int vis[100] = {0};
int ans[6] = {0};
void init_graph(){
    int cnt = 0;
    for(int i = 0;i < 6;i++){
        int k = 1;
        while(FuncList[i](k) < 1000)++k;//注意是＋＋ｋ因为ｋ++，最后出边界的条件是的ｋ和最终的ｋ相差一
        while(FuncList[i](k)< 10000){
            int num = FuncList[i](k++);
            g[num/100].push_back(num);
            cnt ++;
        }
    }
    cout<<"graph has"<<cnt<<"nodes"<<endl;
}

int binary_search(int(*Fun)(int),int y){
    int head = 1,tail = y,mid,temp;
    while(head <= tail){
        mid = (head + tail) / 2;
        temp = Fun(mid);
        if(temp == y) return 1;
        if(temp < y)head = mid + 1;
        else tail = mid - 1;
    }
    return 0;
}

int check(int*num){
    sort(num,num+6);
    do{
        int i;
        for(i = 0;i < 6;i++){
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
        return (x % 100 == ans[0]/100)&&check(ans);
    }
    int index = x % 100;
    for(int i = 0;i < g[index].size();i++){
        int now = g[index][i];
        if(vis[now/100])continue;
        if(dfs(now,d + 1))return 1;
    }

}

int main(){
    init_graph();
    int flag = 1;// 因为需要跳出两层循环
    for(int i = 0;i < 100&&flag;i++){
        for(int j = 0;j < g[i].size()&&flag;j++){
            vis[g[i][j]/100] = 1;
            if(dfs(g[i][j],1))flag = 0;
        }
    }
    for(int i = 0;i < 6;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}
