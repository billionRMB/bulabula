/*************************************************************************
	> File Name: test.c
	> Author:Gin.TaMa 
	> Mail:1137554811@qq.com 
	> Created Time: 2019年01月25日 星期五 13时51分58秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
typedef struct t{
    int a,b;
}T;

T M[10000][4] = {0};
int m_num = 0;
int prime[101] = {0};

void init(){
    for(int i = 2;i <= 100;i ++){
        if(prime[i])continue;
        for(int j = i;j <= 100;j += i){
            if(prime[j])continue;
            //注意一下　这个意识，如果在循环体外部去
            //以某个变量作为条件，那么它并不会改变的意识
            prime[j] = i;
        }
    }
}

int get_m(int a,int b,T* tempm){
    int i = 0,m = 0;;
    while(a>1){
        int tempP = prime[a];m = 0;
        while(a % tempP == 0){
            a /= tempP;
            m ++;
        }
        tempm[i].a = tempP;
        tempm[i].b = m * b;
        i ++;
    }
}

int m_inM(T* m){
    for(int i = 0;i < m_num;i ++){
        if(0 == memcmp(M[i],m,sizeof(m)*4))return 1;
    }
    return 0;
}

void addM(T* m){
    memcpy(M[m_num++],m,sizeof(m)*4);
}

int main(){
    init();
    for(int a = 2;a <= 100;a ++){
        for(int b = 2;b <= 100;b ++){
            T tempm[4] = {0};
            get_m(a,b,tempm);
            if(!m_inM(tempm))addM(tempm);
            /*
            int flag = 1;
            for(int i = 0;i < m_num && flag;i ++){
                flag = memcmp(M[i],tempm,sizeof(tempm));
            }
            flag && memcpy(M[m_num ++],tempm,sizeof(tempm));
            */
        }
    }
    printf("%d\n",m_num);
    return 0;
}
