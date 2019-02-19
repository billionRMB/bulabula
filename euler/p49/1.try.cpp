/*************************************************************************
	> File Name: 1.try.cpp
	> Author:Gin.TaMa 
	> Mail:1137554811@qq.com 
	> Created Time: 2019年01月13日 星期日 16时37分14秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define max 10000
typedef struct D{
    int num;
    int fnum;
}D;

int prime[max + 5] = {0};
int num_fnum[max + 5] = {0};
D dint[max + 5] = {0};
int Dlen = 0;

int get_nint(int n){
    int rnum = 0;
    while(n){
        rnum += 1 << (2 * (n % 10));
        n /= 10;
    }
    return rnum;
}

void init(){
    for(int i = 2;i < max;i ++){
        if(!prime[i]){
            prime[++prime[0]] = i;
            if(i >= 1000){
                dint[Dlen].num = i;
                dint[Dlen].fnum = get_nint(i);
                num_fnum[i] = dint[Dlen].fnum;
                Dlen ++;
            }
        }
        for(int j = 1;j <= prime[0];j ++){
            if(i * prime[j] > max)break;
            prime[i * prime[j]] = 1;
            if(i % prime[j] == 0)break;
        }
    }
}

bool cmp(D a,D b){
    if(a.fnum < b.fnum)return true;
    if(a.fnum == b.fnum && a.num < b.num)return true;
    return false;
}

int main(){
    init();
    sort(dint,dint+Dlen,cmp);
    for(int i = 0;i < 100;i ++){
        printf("%d %d\n",dint[i].num,dint[i].fnum);
    }
    for(int i = 0;i < Dlen - 2;i ++){
        int j = i + 1,nextNum;
        while(dint[j].fnum == dint[i].fnum){
            nextNum = 2 * dint[j].num - dint[i].num;
            if(nextNum >= 10000)break;
            if(num_fnum[nextNum] == dint[i].fnum){
                printf("%d%d%d\n",dint[i].num,dint[j].num,nextNum);
            }
            j ++;
        }
    }
    return 0;
}
