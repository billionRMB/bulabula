/*************************************************************************
	> File Name: try.c
	> Author:Gin.TaMa 
	> Mail:1137554811@qq.com 
	> Created Time: 2019年01月04日 星期五 20时04分00秒
 ************************************************************************/

#include<stdio.h>
#include<inttypes.h>
int main(){
    int m = 20;
    int64_t ans = 1;
    for(int i = 40;i > 20;i --){
        ans *= i;
        while(ans % m == 0 && m != 1){
            ans /= m;
            m --;
        }
    }
    printf("%"PRId64"\n",ans);
    return 0;
}
