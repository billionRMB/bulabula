/*************************************************************************
	> File Name: p4-1.c
	> Author: 
	> Mail: 
	> Created Time: 2018年11月17日 星期六 18时04分31秒
 ************************************************************************/

#include<stdio.h>
int is_valid(int x){
    int num,n;
    num = x;
    n = 0;
    while(x){
        n = 10 * n + x%10;
        x = x/10;
    }
    return num == n;
}


int main(){
    for(int a = 1000;a >100 ;a -- ){
        for(int b = a;b >100 ; b --){
            if(is_valid(a*b)) {
                printf("%d * %d = %d\n",a,b,a*b);
            }
        }
    }
    return 0;
}
