/*************************************************************************
	> File Name: p17.c
	> Author:Gin.TaMa 
	> Mail: 
	> Created Time: 2018年12月19日 星期三 18时15分46秒
 ************************************************************************/

#include<stdio.h>

int get_letter_nums(int x){
    //将只有这个函数体会用的变量封装到函数内 并使用static 来只生成一个 这样就避免了万一其他程序引用了该程序会出现问题
    static int leter_num[20]={
        0,3,3,5,4,4,3,5,5,4,3,
        6,6,8,8,7,7,9,8,8
    };
    //20 - 90 几十的英文单词长度
    static int leter_num2[10]={
        0,0,6,6,5,5,5,7,6,6
    };
    if (x < 20){
        return leter_num[x];
    }else if(x < 100){
        return leter_num2[x/10] + leter_num[x % 10];
    }else if(x < 1000){
        if(x % 100 == 0){
            return leter_num[x / 100] + 7;
        }
        return leter_num[x / 100] + 10 + get_letter_nums(x % 100);
    }return 11;
}

int main(){
    int ans = 0;
    for(int i = 1;i <= 1000;i ++){
        ans += get_letter_nums(i);
    }
    printf("%d\n",ans);
    return 0;
}
