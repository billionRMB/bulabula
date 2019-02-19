/*************************************************************************
	> File Name: test.c
	> Author:Gin.TaMa 
	> Mail:1137554811@qq.com 
	> Created Time: 2019年01月23日 星期三 16时56分22秒
 ************************************************************************/

#include<stdio.h>
#include<inttypes.h>
int64_t f(int64_t n){
    return (3 * n - 1) * n / 2;
}

int b_search(int64_t (*f)(int64_t),int64_t x){
    int64_t head = 0,tail = x,mid,tempM;
    while(head <= tail){
        mid = (head + tail) / 2;
        tempM = f(mid);
        if(tempM == x)return mid;
        if(tempM < x)head = mid + 1;
        else tail = mid - 1;
    }
    return 0;
}

int main(){
    int i = 1;
    int ans = INT32_MAX;
    while(f(i + 1) - f(i) < ans){
        int j = i + 1;
        int64_t minus;
        do{
            minus = f(j) - f(i);
            int64_t add = f(j) + f(i);
            if(b_search(f,minus)&&b_search(f,add)){
                ans = minus < ans ? minus:ans;
                printf("%"PRId64"\n",minus);
                break;
            }
            j ++;
        }while(minus < ans);
        i++;
    }
    printf("%d\n",ans);
    return 0;
}
