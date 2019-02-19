/*************************************************************************
	> File Name: random.try.cpp
	> Author:Gin.TaMa 
	> Mail:1137554811@qq.com 
	> Created Time: 2019年01月14日 星期一 14时31分06秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define max 10000
struct D{
    int num,fnum;
};
int prime[max + 5] = {0};
int i_fnum[max + 5] = {0};
D dnum[max + 5] = {0};
int dlen = 0;

int get_fnum(int i){
    int f = 0;
    while(i){
        f += 1 << (i % 10 * 2);
        i /= 10;
    }
    return f;
}

void init(){
    for(int i = 2 ;i < max;i ++){
        if(!prime[i]){
            prime[++prime[0]] = i;
            if(i > 1000){
            dnum[dlen].num = i;
            dnum[dlen].fnum=get_fnum(i);
            i_fnum[i] = dnum[dlen].fnum;
            dlen ++;
            };
        }
        for(int j = 1;j <= prime[0];j ++){
            if(i * prime[j] > max)break;
            prime[i * prime[j]] = 1;
            if(i % prime[j] == 0)break;
        }
    }
}

bool cmp(D a,D b){
    if(a.fnum < b.fnum) return true;
    if(a.fnum == b.fnum && a.num < b.num)return true;
    return false;
}

int main(){
    init();
    sort(dnum,dnum + dlen,cmp);
    for(int i = 0;i < dlen- 2;i ++){
        int j = i + 1;
        while(dnum[i].fnum == dnum[j].fnum){
            int next = dnum[j].num * 2 - dnum[i].num;
            if(next > 10000)break;
            if(i_fnum[next] == dnum[i].fnum){
                printf("%d%d%d\n",dnum[i].num,dnum[j].num,next);
            }
            j++;
        }
    }
    
    return 0;
}
