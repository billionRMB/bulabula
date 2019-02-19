/*************************************************************************
	> File Name: 1.try.c
	> Author:Gin.TaMa 
	> Mail:1137554811@qq.com 
	> Created Time: 2019年01月09日 星期三 23时43分46秒
 ************************************************************************/

#include<stdio.h>
#define max_n 1000000
#include<math.h>
#define p(n){\
    printf("%s %d\n",#n,n);\
}

int prime[max_n + 5] = {0};
void init(){
    for(int i = 2; i <  max_n;i ++){
        if(!prime[i])prime[++prime[0]] = i;
        for(int j = 1;j <= prime[0];j++){
            if(i * prime[j] > max_n)break;
            prime[i * prime[j]] = 1;
            if(i % prime[j] == 0)break;
        }
    }
}

int binery_search(int * num,int x,int n){
    int head = 1,tail = n,mid,temp;
    while(head <= tail){
        mid = (head + tail) / 2;
        temp = num[mid];
        if(temp == x)return mid;
        if(temp < x)head = mid + 1;
        else tail = mid - 1;
    }
    return -1;
}

int is_vaild(int n){
    int lengh = pow(10,floor(log10(n)));
    int temp = 1;
    for(int i = 1;i < lengh;i *= 10){
        temp = n / 10 + n % 10 * lengh;
        n = temp;
        if(binery_search(prime,temp,prime[0]) ==-1)
            return 0;
    }
    return 1;
}

int main(){
    init();
    int sum = 0;
    for(int i = 1;i <= prime[0];i ++){
        if(!is_vaild(prime[i]))continue;
        sum ++;
        //printf("%d\n",prime[i]);
    }
    p(sum);
    return 0;
}
