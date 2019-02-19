/*************************************************************************
	> File Name: test.cpp
	> Author:Gin.TaMa 
	> Mail:1137554811@qq.com 
	> Created Time: 2019年01月22日 星期二 23时50分28秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define max  10000
struct Num{
    int num;
    int d_num;
};
int prime[max + 5] = {0};
Num num[max] = {0};
int num_len = 0;
int dnum[max] = {0};
int get_d(int x){
    int d = 0;
    while(x){
        d += 1 << ((x % 10) * 2);
        x /= 10; 
    }
    return d;
}
//初始化所有的四位数的素数
void init(){
    for(int i = 2;i < max;i ++){
        if(!prime[i]){
            prime[++prime[0]] = i;
            if(i > 1000){
            num[num_len].num = i;
            num[num_len].d_num = get_d(i);
            dnum[i] = num[num_len].d_num;
            num_len ++;
            }
        }
        for(int j = 1;j <= prime[0];j ++){
            if(i * prime[j] > max)break;
            prime[i * prime[j]] = 1;
            if(i % prime[j] == 0){
                break;
            }
        }
    }
}

int cmp(Num a,Num b){
    if(a.d_num < b.d_num)return 1;
    if(a.d_num == b.d_num && a.num < b.num)return 1;
    return 0;
}

int main(){
    init();
    sort(num,num+num_len,cmp);
    for(int i = 0;i < num_len - 2;i ++){
        int j = i + 1;
        do{
            int nextP = 2 * num[j].num - num[i].num;
            if(nextP > 10000)break;
            if(dnum[nextP] == num[i].d_num){
                printf("%d%d%d\n",num[i].num,num[j].num,nextP);
            }
            j ++;
        }while(num[j].d_num == num[i].d_num);
    }
    return 0;
}
