/*************************************************************************
	> File Name: 1.try.c
	> Author:Gin.TaMa 
	> Mail:1137554811@qq.com 
	> Created Time: 2019年01月10日 星期四 16时45分36秒
 ************************************************************************/

#include<stdio.h>
#include<math.h>

#define max 1000000
int num[max + 5] ={0};

void init(){
    for(int i = 1;i < max;i++){
        int len = pow(10,floor(log10(i)));
        int temp = i;
        while(len){
            num[++num[0]] = temp / len;
            if(num[0] > max)return;
            temp %= len;
            len /= 10;
        }
    }

    return ;
}

int get_num(int x){
    return num[x];
}

int main(){
    init();
    for(int i = 1;i < 30;i ++){
        printf("%d",num[i]);
    }
    printf("\n");
    int ans = 1;
    for(int i = 1;i < 1000000;i *= 10){
        ans *= get_num(i);
    }
    printf("%d\n",ans);
    return 0;
}
