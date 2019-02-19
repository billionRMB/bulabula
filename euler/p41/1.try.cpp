/*************************************************************************
	> File Name: 1.try.c
	> Author:Gin.TaMa 
	> Mail:1137554811@qq.com 
	> Created Time: 2019年01月11日 星期五 09时40分25秒
 ************************************************************************/
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define test_round 30

#define p(n){\
    printf("%s %d\n",#n,n);\
}

int ml_test(int*num,int n){
    int64_t x = 0, a, m, ans;
    // 必须使用ｉｎｔ６４因为a = a * a 可能会炸
    while(n --){
        //此时的ｎ为ｎ--后的值
        x = x * 10 + num[n];
    }

    for(int i = 0;i < test_round;i ++){
        a = (rand() %(x - 1)) + 1;
        // a 有范围　
        m = x - 1;
        ans = 1;
        while(m){ 
            if(m & 1)ans = a * ans % x;
            a = a * a % x;
            m >>= 1;
        }
        if(ans != 1)return 0;
    }

    return x;
}

int main(){
    srand(time(0));
    
    int num[9] = {0};
    int ans = 0,temp_ans = 0;
    int i = 7;
    
    for(int j = 0;j < i; ++j){
        num[j] = j + 1;
    }
    
    do{
        temp_ans = ml_test(num,i);
        if(temp_ans > ans)ans = temp_ans;
    }while(next_permutation(num,num + i));
    
    cout<<ans<<endl;
    return 0;
}
