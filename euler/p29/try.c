/*************************************************************************
	> File Name: try.c
	> Author:Gin.TaMa 
	> Mail:1137554811@qq.com 
	> Created Time: 2019年01月08日 星期二 20时21分58秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
typedef struct Turple{
    int p,a;
}Turple;

Turple M[10000][4] = {0};
int prime[104] = {0};
void init(){
    for(int i = 2;i < 101;i++){
        if(prime[i])continue;
        for(int j = i;j < 101;j += i){
            if(prime[j])continue;
            prime[j] = i;
        }
    }
}

void get_m(int a,int b,Turple*m){
    int m_len = 0;
    int len = 0,m_pri;
    while(a != 1){
        len = 0,m_pri = prime[a];
        while(a % m_pri == 0){
            len ++;
            a /= m_pri; 
        }
        m[m_len].p = m_pri;
        m[m_len ++].a = len * b;
    }
}


int main(){
    int flag = 1;
    int M_num = 0;
    init();
    for(int a = 2;a <= 100;a ++){
        for(int  b = 2;b <= 100;b ++){
            Turple m[4] = {0};
            get_m(a,b,m);
            flag = 1;
            for(int i = 0;i < M_num && flag;i ++){
                flag = memcmp(M[i],m,sizeof(m));
            }
            flag && memcpy(M[M_num ++],m,sizeof(m));
        }
    }
    printf("%d\n",M_num);
    return 0;
}
