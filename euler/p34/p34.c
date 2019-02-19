/*************************************************************************
	> File Name: p30-1.c
	> Author: 
	> Mail: 
	> Created Time: 2018年11月17日 星期六 20时28分23秒
 ************************************************************************/

#include<stdio.h>

#define MAX_N 2540160 
int j[10] = {0};
int jc(int x){
    int sum = 1;
    for(int i =1;i <=x ;i++){
        sum *= i;
    }
    return sum;
}


int is_vaild(long long int x){
    long long int temp = x, sum = 0;
    while(x){
        sum += j[x%10];
        x /= 10;
    }
    return temp == sum; 
} 

int main(){
    for(int i = 0;i < 10;i ++){
        j[i] = jc(i);
    }
    long long int sum = 0;

    for(long long int i = 3; i <= MAX_N ; i++){
        if(!is_vaild(i)) continue;
        sum += i;
    }

    printf("%lld\n",sum);
    return 0;
}
