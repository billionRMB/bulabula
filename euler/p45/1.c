/*************************************************************************
	> File Name: 1.c
	> Author:Gin.TaMa 
	> Mail:1137554811@qq.com 
	> Created Time: 2018年12月22日 星期六 10时57分41秒
 ************************************************************************/

#include<stdio.h>
#include<inttypes.h>
int H(int x){
    return x * (x + 1)/2;
}
int P(int x){
    return x * (3 * x - 1)/2;
}

int is_p(int h_x){
    int l = 0,r = H(h_x),mid;
    while(l < r){
        
    }
}

int main(){
    int64_t i = 1,j = 1,ans = INT64_MAX; 
    while(H(i) <= P(j)){
        j ++;
        do{
            i = j + 1;
            if(H(i) == P(i)){
                ans = H(i);
                break;
            }
            i ++;
        }while(H(i) <= P(j));
    }
    printf("%"PRId64"\n",ans);
    return 0;
}
