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
        temp = (num[mid] < 0 ? -num[mid] :num[mid]);
        if(temp == x)return mid;
        if(temp < x)head = mid + 1;
        else tail = mid - 1;
    }
    return -1;
}

int is_vaild(int n){
    int lengh = pow(10,floor(log10(n)));
    int temp = 1;
    int cnt = 0;
    int temp_n = -1;
    for(int i = 1;i <= lengh;i *= 10){
        temp = n / 10 + n % 10 * lengh;
        n = temp;
        temp_n = binery_search(prime,temp,prime[0]);
        if(temp_n == -1)
            return -1;
        if(prime[temp_n] < 0)continue;
        prime[temp_n] *= -1;
        cnt ++;
    }
    return cnt;
}

int main(){
    init();
    int sum = 0,cnt;
    for(int i = 1;i <= prime[0];i ++){
        if(prime[i] < 0)continue;
        cnt = is_vaild(prime[i]);
        if(cnt == -1)continue;
        sum += cnt;
        //printf("%d %d \n",-prime[i],cnt);
    }
    p(sum);
    return 0;
}
