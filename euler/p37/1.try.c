/*************************************************************************
	> File Name: 1.try.c
	> Author:Gin.TaMa 
	> Mail:1137554811@qq.com 
	> Created Time: 2019年01月10日 星期四 09时33分56秒
 ************************************************************************/

#include<stdio.h>
#include<math.h>
#define max 1000000
#define p(n){\
    printf("%s %d\n",#n,n);\
}

int prime[max + 5] = {0};

void init(){
    for(int i = 2;i < max;i ++){
        if(!prime[i])prime[++prime[0]] = i;
        for(int j = 1;j <= prime[0];j ++){
            if(i * prime[j] > max) break;
            prime[i * prime[j]] = 1;
            if(i % prime[j] == 0)break;
        }
    }
}

int b_search(int * num,int x,int n){
    int head = 1,tail = n,mid,temp;
    while(head <= tail){
        mid = (head + tail) /2;
        temp = num[mid];
        if(temp == x)return mid;
        if(temp < x)head = mid + 1;
        else tail = mid - 1;
    }
    return -1;
}

int is_vaild(int n){
    int lengh,temp = n;
    lengh = pow(10,floor(log10(temp))); 
    while(n){
        if(b_search(prime,n,prime[0])==-1)return 0;
        n /= 10;
    }
    while(lengh != 1){
        temp %= lengh;
        if(b_search(prime,temp,prime[0]) == -1)
            return 0;
        lengh /= 10;
    }
    return 1;
}


int main(){
    init();
    int sum = 0;
    int cnt = 0;
    for(int i = 5;i <= prime[0]||cnt < 11;i ++){
        if(!is_vaild(prime[i]))continue;
        sum += prime[i];
        cnt ++;
        p(prime[i]);
    }
    printf("%d %d\n",cnt,sum);
    return 0;
}
