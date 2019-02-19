/*************************************************************************
	> File Name: random.try.c
	> Author:Gin.TaMa 
	> Mail:1137554811@qq.com 
	> Created Time: 2019年01月14日 星期一 13时01分18秒
 ************************************************************************/

#include<stdio.h>
#include<math.h>
int get_d(int n){
    return floor(log10(n)) + 1;
}

int get_r(int n){
    int r = 0;
    while(n){
        r += 1 <<(2 * (n % 10));
        n /= 10;
    }
    return r;
}

int is_vaild1(int a,int b,int c){
    return get_r(123456789) == (get_r(a) + get_r(b) + get_r(c));
}

int get_er(int n){
    while(n){
        printf("%d",n&1);
        n >>= 1;
    }
    printf("\n");
}

int dnum[10000] = {0};
int main(){
    int ans = 0;
    for(int a = 1;2 * get_d(a) + get_d(a * a) < 10;a ++){
        for(int b = a + 1;get_d(a) + get_d(b) + get_d(a * b) < 10;b ++){
            if(get_d(a) + get_d(b) + get_d(a * b) != 9)continue;
            if(is_vaild1(a,b,a * b)){
                if(!dnum[a * b]){
                    printf("%d *  %d = %d\n",a,b,a * b);
                    ans += a*b;
                    dnum[a * b] = 1;
                }
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
