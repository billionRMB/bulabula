/*************************************************************************
	> File Name: 2.c
	> Author:Gin.TaMa 
	> Mail:1137554811@qq.com 
	> Created Time: 2018年12月22日 星期六 11时18分02秒
 ************************************************************************/

#include<stdio.h>
#include<inttypes.h>
int64_t triangle(int64_t n){
    return n * (n + 1)/2;
}

int64_t pentagonal(int64_t n){
    return n * (3 * n - 1)/2;
}

int64_t hexagonal(int64_t n){
    return n * (2 * n - 1);
}
int64_t binary_search(int64_t (*num)(int64_t),int64_t n,int64_t x){
    int64_t head = 0,tail = n - 1,mid;
    while(head <= tail){
        mid = (head + tail) >> 1;
        if(num(mid) == x)return mid;
        if(num(mid) < x)head = mid +1;
        else tail = mid - 1;
    }
    return  -1;
}
int64_t is_h(int64_t p_x){
    int64_t l = 144,r = p_x,mid;
    while(l <= r){
        mid = (l + r) >> 1;
        if(mid < l)return 0;
        if(hexagonal(mid) == pentagonal(p_x)){
            return 1;
        }
        if(hexagonal(mid) < pentagonal(p_x)){
            l = mid + 1;
        }
        else r = mid - 1;
    }
    return 0;
}

int64_t main(){
    int64_t n = 144;
    while(binary_search(pentagonal,2 * n, hexagonal(n)) == -1)n++;
    printf("%"PRId64"\n",hexagonal(n));
    
    n = 166;
    while(!is_h(n)){
        n++;
    }
    printf("%"PRId64"\n",pentagonal(n));
    return 0;
}
