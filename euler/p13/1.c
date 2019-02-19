/*************************************************************************
	> File Name: 1.c
	> Author:Gin.TaMa 
	> Mail: 
	> Created Time: 2018年12月19日 星期三 18时56分05秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
//试着写一下大整数 * 大整数
void calu(){
    char read_num[55];
    int ans[55] = {1};
    ans[0] = ans[1] = 1;
    int m,m1;
    int n;
    scanf("%d %d",&n,&m);
    printf("n = %d m = %d\n",n,m);
    m1 = m;
    while(m--){
        for(int i = 1;i <= ans[0] ;i ++){
            ans[i] *= n;//倒着处理进位所以直接这样计算就可以
        }
        for(int i = 1;i < ans[0];i++){
            if(ans[i] < 10)continue;
            ans[i+1] += ans[i]/10;
            ans[i] %= 10;
            ans[0] += (ans[0] == i);
        }
    }
    printf("pow(%d,%d)=",n,m1);
    for(int i = ans[0];i;i --){
        printf("%d",ans[i]);
    }
    printf("\n");
}

int main(){
   // calu();    
    char read_num[55];// 50 位数相加最多52 位
    int ans[55] = {0};
    while(scanf("%s",read_num)!= EOF){
        int len = strlen(read_num);//该字符的长度是多少
        if(len > ans[0]) ans[0] = len;
        for(int i = 0;read_num[i];i ++){
            //当 read_num 到最后了 即为\0
            ans[len - i] += read_num[i] - '0';
            // 倒着读入了
        }
        for(int i = 1;i <= ans[0];i ++){
            if(ans[i] <  10)continue;
            ans[i + 1] += ans[i] / 10;
            ans[i] %= 10;
            ans[0] += (i == ans[0]);//用了减少编译器的分支预测
        }
    }
    for(int i = ans[0] ;i > ans[0] - 10 ;i --){
        printf("%d",ans[i]);
    }
    printf("\n");
    return 0;
}
