/*************************************************************************
	> File Name: test2.c
	> Author:Gin.TaMa 
	> Mail:1137554811@qq.com 
	> Created Time: 2019年01月25日 星期五 14时32分39秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
typedef struct T{
    int a,b;
}T;

T M[10000][4] = {0};
int mNum = 0;
int prime[105] = {0};

void init(){
    for(int i = 2;i < 101;i ++){
        if(prime[i])continue;
        for(int j = i;j < 101;j += i){
            // j += i .....
            if(prime[j])continue;
            prime[j] = i;
        }
    }
}

void get_m(int a,int b,T* m){
    int i = 0;
    while(a > 1){
        int temp = prime[a],bl = 0;
        while(a % temp == 0){
            a /= temp;
            bl ++;
        }
        m[i].a = temp;
        m[i].b = bl * b;
        i ++;
    }
}

int mInM(T * m){
    for(int i = 0;i < mNum;i ++){
        if(0 == memcmp(M[i],m,sizeof(m)*4))return 1;
    }
    return 0;
}

int main(){
    init();
    for(int a = 2;a <= 100;a ++){
        for(int b = 2; b <= 100;b ++){
            T temp[4] = {0};
            get_m(a,b,temp);
            if(!mInM(temp))memcpy(M[mNum ++],temp,sizeof(temp));
        }
    } 
    printf("%d\n",mNum);
    return 0;
}
