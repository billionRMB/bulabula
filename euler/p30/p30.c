/*************************************************************************
	> File Name: p30.c
	> Author: 
	> Mail: 
	> Created Time: 2018年11月17日 星期六 19时57分44秒
 ************************************************************************/

#include<stdio.h>
#include<math.h>
#define MAX_N 354294

int is_vaild(int x){
    int temp = x;
    int sum = 0;
    while(x){
        sum += (int)pow(x % 10,5);
        x /= 10;
    }
    return temp == sum;
}

int main(){
    int sum = 0;
    for(int i = 2;i <= MAX_N ;i ++){
        if(!is_vaild(i)) continue;
        printf("%d\n",i);
        sum += i;
    }
    printf("\n%d\n",sum);
    return 0;
}
