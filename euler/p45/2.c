/*************************************************************************
	> File Name: 2.c
	> Author:Gin.TaMa 
	> Mail:1137554811@qq.com 
	> Created Time: 2018年12月22日 星期六 11时18分02秒
 ************************************************************************/

#include<stdio.h>

int triangle(int n){
    return n * (n + 1)/2;
}

int pentagonal(int n){
    return n * (3 * n - 1)/2;
}

int hexagonal(int n){
    return n * (2 * n - 1);
}
int binary_search(int (*num)(int),int n,int x){
    int head = 0,tail = n - 1,mid;
    while(head <= tail){
        mid = (head + tail) >> 1;
        if(num(mid) == x)return mid;
        if(num(mid) < x)head = mid +1;
        else tail = mid - 1;
    }
    return  -1;
}
int is_h(int p_x){
    int l = 144,r = p_x,mid;
    while(l <= r){
        mid = (l + r) >> 2;
        if(hexagonal(mid) == pentagonal(p_x))return 1;
        if(hexagonal(mid) < pentagonal(p_x))l = mid + 1;
        else r = mid - 1;
    }
    return 0;
}

int main(){
    int n = 144;
    while(binary_search(pentagonal,2 * n, hexagonal(n)) == -1)n++;
    printf("%d\n",hexagonal(n));
    return 0;
}
