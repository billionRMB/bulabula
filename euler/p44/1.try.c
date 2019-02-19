/*************************************************************************
	> File Name: 1.try.c
	> Author:Gin.TaMa 
	> Mail:1137554811@qq.com 
	> Created Time: 2019年01月12日 星期六 16时12分57秒
 ************************************************************************/

#include<stdio.h>
#include<inttypes.h>
#define max 100000
int64_t pn(int64_t n){
    return n * (3 * n - 1) / 2;
}

int64_t bineary_searc(int64_t(*f)(int64_t),int64_t x){
    int64_t head = 0,tail = x,mid;
    int64_t temp_mid;
    while(head <= tail){
        mid = (head + tail) / 2;
        temp_mid = f(mid);
        if(temp_mid == x)return mid;
        if(temp_mid < x)head = mid + 1;
        else tail = mid - 1;
    }
    return 0;
}
int64_t is_vaild(int64_t j,int64_t i){
    if(bineary_searc(pn,j + i) && bineary_searc(pn,j - i))
    return j - i;
    return 0;
}

int main(){
    int64_t i = 1,j = 1,temp,ans =INT32_MAX;
    while(pn(j + 1) - pn(j) < ans){
        j++;
        i = j - 1;
        do{
            temp = is_vaild(pn(j),pn(i));
            temp && (ans = (ans < temp ? ans :temp));
            i --;
        }while(i >= 1 && pn(j) - pn(i) < ans);
    }
    printf("%"PRId64"\n",ans);
    return 0;
}
