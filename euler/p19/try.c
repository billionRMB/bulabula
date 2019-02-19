/*************************************************************************
	> File Name: 1.c
	> Author:Gin.TaMa 
	> Mail:1137554811@qq.com 
	> Created Time: 2019年01月05日 星期六 11时47分57秒
 ************************************************************************/

#include<stdio.h>

int get_day(int year,int month,int day){
    if(month == 1|| month == 2)
        year --,month += 12;
    int c = year / 100;
    int y = year - c * 100;
    int week = y+y/4+c/4-2*c+26*(month+1)/10+day-1;
    while(week < 0) week+=7;
    return week % 7;
}
int main(){
    int ans = 0;
    for(int year = 1901;year <= 2000;year ++){
        for(int month = 1;month <= 12;month ++){
            if(6 == get_day(year,month,1))ans ++;
        }
    }
    printf("%d\n",ans);
    
    return 0;
}
