/*************************************************************************
	> File Name: try.c
	> Author:Gin.TaMa 
	> Mail:1137554811@qq.com 
	> Created Time: 2019年01月09日 星期三 15时31分46秒
 ************************************************************************/

#include<stdio.h>
#include<math.h>
int pow5n[10] = {0};
void init(){
    for(int i = 0;i <= 9;i ++){
        pow5n[i] = pow(i,5);
    }
}

int is_vaild(int n){
    int temp = n;
    int sum = 0;
    while(n){
        sum += pow5n[n % 10];
        n /= 10;
    }
    return (sum == temp);
}


int main(){
    init();
    int sum = 0;
    for(int i = 2;i <= 900000;i++){
        if(is_vaild(i))sum+=i;
    }
    printf("%d\n",sum);
    return 0;
}
