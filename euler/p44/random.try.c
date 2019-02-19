/*************************************************************************
	> File Name: random.try.c
	> Author:Gin.TaMa 
	> Mail:1137554811@qq.com 
	> Created Time: 2019年01月18日 星期五 14时30分58秒
 ************************************************************************/

#include<stdio.h>
#include<inttypes.h>
int64_t f(int64_t x){
    return x * (3 * x - 1) / 2;
}

int bineary_search(int64_t (*fun)(int64_t),int64_t aim){
    int64_t head = 0,tail = aim,mid ,temp;
    while(head <= tail){
        mid = (head + tail)/2;
        temp = fun(mid);
        if(temp == aim)return mid;
        if(temp < aim)head = mid + 1;
        else tail = mid - 1;
    }
    return -1;
}
int main(){
    int j = 1;
    int64_t ans = INT64_MAX;
    while(f(j + 1) - f(j) < ans){
        j ++;
        int i = j - 1;
        int64_t temp;
        do{
            temp = f(j) - f(i);
            if(bineary_search(f,temp)!= - 1&&bineary_search(f,f(j) + f(i))!=-1){
                if(temp < ans)ans = temp;
                printf("%"PRId64"\n",temp);
            }
            i--;
        }while(f(j) - f(i) < ans && i > 0);
    }
    return 0;
}
