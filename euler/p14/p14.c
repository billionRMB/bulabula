/*************************************************************************
	> File Name: p14.c
	> Author:Gin.TaMa 
	> Mail: 
	> Created Time: 2018年11月24日 星期六 20时08分07秒
 ************************************************************************/

#include<stdio.h>
#include<inttypes.h>
#define MAX 1000000
#define keep_range 1000000

int keep[keep_range] = {0};

int get_l(int64_t x){
    if(x == 1)return 1;
    if(x <= keep_range && keep[x])return keep[x];
    int temp = 0;
    if(x & 1) temp = get_l(x*3 + 1) +1;
    else temp = get_l(x/2) +1;
    if(x <= keep_range)keep[x] = temp;
    return temp;
}


int get_length(int64_t n){
    if(n == 1) return 1;
    int len = 0;
    while(n != 1){
        len ++;
        if(!(n & 1)) n = n/2;
        else n = (3*n + 1);
    }
    return len;
}


int main(){
    int ans = 0,ans_len = 0;
    for(int i = 1; i < MAX ; i++){
        int temp_len = get_l(i);
        if(temp_len > ans_len){
            ans = i;
            ans_len = temp_len;
        }
    }
    printf("%d(%d)\n",ans,ans_len);
    return 0;
}
