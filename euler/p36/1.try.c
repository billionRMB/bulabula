/*************************************************************************
	> File Name: 1.try.c
	> Author:Gin.TaMa 
	> Mail:1137554811@qq.com 
	> Created Time: 2019年01月10日 星期四 09时16分11秒
 ************************************************************************/

#include<stdio.h>
#define max 1000000

#define p(n){\
    printf("%s %d\n",#n,n);\
}

int is_vaild10(int n){
    int ans = n,temp = 0;
    while(n){
        temp = temp * 10 + n % 10;
        n /= 10;
    }
    return temp == ans;
}

int is_vaild2(int n){
    int ans = n,temp = 0;
    while(n){
        temp = temp << 1 | (n & 1);
        n >>= 1;
    }
    return ans == temp;
}

int main(){
    int sum = 0;
    //p(is_vaild10(585));
    //p(is_vaild2(585));
    for(int i = 1;i <= max;i ++){
        if(is_vaild10(i)&&is_vaild2(i)){
            sum += i;
            //p(i);
        }
    }
    p(sum);
    return 0;
}
