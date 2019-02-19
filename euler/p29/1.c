/*************************************************************************
	> File Name: 1.c
	> Author:Gin.TaMa 
	> Mail:1137554811@qq.com 
	> Created Time: 2018年12月28日 星期五 18时59分51秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
struct Tuple {
    int p,a;
};

struct Tuple M[10000][4] = {0};
int prime[105] = {0};
int m_num = 0;

void init(){
    for(int i = 2;i <= 100;i ++){
        if(prime[i])continue;
        for(int j = i;j <= 100;j += i){
            if(prime[j])continue;
            prime[j] = i;
        }
    }
}

int get_m(int a,int b,struct Tuple * M){
    int m_len = 0;
    while(a != 1){
        int pre_m = prime[a],len = 0;
        while(a % pre_m == 0){
            len ++;
            a /= pre_m;
        }
        M[m_len].p = pre_m;
        M[m_len].a = len * b;
        m_len ++;
    }
}

int main(){
    init();
    for(int a = 2;a <= 100;a ++){
        for(int b = 2;b <= 100; b++){
            struct Tuple temp_m[4] = {0};
            get_m(a,b,temp_m);
            int flag = 1;
            for(int i = 0;i < m_num&& flag;i ++){
                flag = memcmp(M[i],temp_m,sizeof(temp_m));
            }
            flag&&(memcpy(M[m_num ++],temp_m,sizeof(temp_m)));
        }
    }
    printf("%d\n",m_num);
    return 0;
}
