/*************************************************************************
	> File Name: p8-1.c
	> Author:Gin.TaMa 
	> Mail: 
	> Created Time: 2018年11月24日 星期六 16时29分15秒
 ************************************************************************/

#include<stdio.h>
#include<inttypes.h>
#include"r.h"
#define max_n 10000

#define num_l 13

int64_t calculate(){
    int64_t p = 1,ans = 1;
    int zero = 0,n = 0;
    for(int i = 0 ;num[i];i++){
        if(num[i]=='0') zero++;
        if(!zero) {
            p *= (num[i] - '0');
            n ++;
        }
        else{
            zero = 0;
            n = 0;
            p = 1;
        }
        if(n > num_l){
            p /= (num[i - 13] - '0');
            n--;
        }
        if(p > ans) ans = p;
    }
    return ans;
}



int main(){
    int64_t  p = 1, zero = 0, ans = 1;
    for(int i = 0 ; num[i] ;i++){
        //换一种遍历的方式
        if (num[i] == '0'){
            zero ++;
        }else {
            p *= (num[i] - '0');
        }
        if(i >= 13){
            if(num[i - 13] == '0'){
                zero --;
            }else{
                p /= (num[i - 13]-'0');
            }
        }
        if(zero == 0 && ans < p) ans = p;
    }
    printf("%"PRId64"\n",ans);
    printf("%"PRId64"\n",calculate());
    return 0;
}
