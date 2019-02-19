/*************************************************************************
	> File Name: random.try.c
	> Author:Gin.TaMa 
	> Mail:1137554811@qq.com 
	> Created Time: 2019年01月18日 星期五 13时51分31秒
 ************************************************************************/

#include<stdio.h>
int f3(int i){
    return i * (i + 1) / 2;
}

int f5(int x){
    return x * (3 * x - 1)/2;
}

int f6(int x){
    return x * ( 2 * x - 1 );
}

int binery_search(int (* f)(int ),int n){
    int head = 0,tail = n,mid ,tempMid ;
    while(head <= tail){
        mid = (head + tail)/2;
        tempMid = f(mid);
        if(tempMid == n)return mid;
        if(tempMid < n)head = mid + 1;
        else tail = mid - 1;
    }
    return 0;
}
#define max 100000

int main(){
    for(int i = 40756;i < max;i ++){
        if(binery_search(f3,i)&&binery_search(f5,i)&&binery_search(f6,i)){
            printf("%d\n",i);
            break;
        }
    }
    return 0;
}
