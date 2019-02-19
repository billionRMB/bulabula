/*************************************************************************
	> File Name: test.c
	> Author:Gin.TaMa 
	> Mail:1137554811@qq.com 
	> Created Time: 2019年01月22日 星期二 22时45分48秒
 ************************************************************************/

#include<stdio.h>
// 定义上限
#define max 1000
//存储素数
int prime[max + 5] = {0};
//存储和
int sum[max] = {0};
//线性筛素数
void init(){
    for(int i = 2;i < 100;i++){
        if(!prime[i]){
            prime[++prime[0]] = i;
            //处理累加
            sum[prime[0]] = sum[prime[0] - 1] + i;
        }
        for(int j = 1;j <= prime[0];j ++){
            if(i * prime[j] > max)break;
            prime[i * prime[j]] = 1;
            if(i % prime[j] == 0)break;
        }
    }
}
int is_prime(int x){
    int head = 1,tail = prime[0],mid,tempMid;
    while(head <= tail){
        mid = (head + tail) / 2;
        tempMid = prime[mid];
        if(tempMid == x)return 1;
        if(tempMid < x)head = mid + 1;
        else tail = mid - 1;
    }
    return 0;
}
int main(){
    init();
    // 测试一下
    int maxN = 1;// 用来剪枝
    int ans_prime = 2;
    for(int i = 1;i + maxN <= prime[0];i ++){
        for(int j = maxN;j + i <= prime[0];j ++){
            if(is_prime(sum[i + j] - sum[i - 1])){
                ans_prime = sum[i + j] - sum[i - 1];
                maxN = j+1;
            }
        }
    }
    printf("%d %d\n",maxN,ans_prime);
    return 0;
}
