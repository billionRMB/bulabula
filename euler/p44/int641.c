/*************************************************************************
	> File Name: 1.c
	> Author:Gin.TaMa 
	> Mail:1137554811@qq.com 
	> Created Time: 2018年12月22日 星期六 09时16分37秒
 ************************************************************************/

#include<stdio.h>
#include<inttypes.h>
int64_t pentagonal(int64_t x){
    return x * (3 * x - 1)/2;
}
// 没有用数组，因为数组本质上是个映射关系，这里映射关系是明确的所以不用数组
// 用个函数就好；
// 下面的函数是在二分查找一个结果等于 x  
int64_t is_pentagonal(int64_t x){
    int64_t head = 1,tail = 10000;
    int64_t mid;
    while(head <= tail){
        mid = (head + tail)>>1;// 注意右移一位来做/2 的运算
        if ( pentagonal(mid)==x )return 1;
        if(pentagonal(mid) < x) head = mid + 1;
        else tail = mid - 1;
    }
    return 0;
}

int main(){
    //就是只有在有可能出现的最小值的区间去搜索
    int64_t i = 1,j = 1,ans = INT32_MAX;
    //动态的上界 注意
    while(pentagonal(j + 1) - pentagonal(j) < ans){
        j++;
        i = j -1;
        do{
            if(is_pentagonal(pentagonal(i) + pentagonal(j))&& is_pentagonal(pentagonal(j) - pentagonal(i))){
                ans = pentagonal(j) - pentagonal(i) < ans ? pentagonal(j) - pentagonal(i) : ans;
            }
            i--;
        }while(i >= 1 && pentagonal(j) - pentagonal(i) < ans);//减枝,bound函数
    }
    printf("%"PRId64"\n",ans);
    return 0;
}
