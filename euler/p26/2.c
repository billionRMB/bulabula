/*************************************************************************
	> File Name: 2.c
	> Author:Gin.TaMa 
	> Mail:1137554811@qq.com 
	> Created Time: 2018年12月26日 星期三 20时14分34秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#define max_n 1000
int dnum[max_n + 5];

int get_len(int d){
    memset(dnum,0,sizeof(dnum));
    int y = 1,n = 1;
    while(y && dnum[y] == 0){
        dnum[y] = n;
        y = 10 * y % d;
        n++;
    }
    return y ? n - dnum[y] : 0;
}

int main(){
    int max_len = 0, ans =0;
    for(int d = 2;d < max_n; d++){
        int temp_len = get_len(d);
        if(temp_len > max_len){
            max_len = temp_len;
            ans = d;
        }
    }
    printf("%d %d\n",max_len,ans);
    return 0;
}
