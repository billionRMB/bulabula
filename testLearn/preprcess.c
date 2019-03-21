/*************************************************************************
	> File Name: preprcess.c
	> Author:Gin.TaMa 
	> Mail:1137554811@qq.com 
	> Created Time: 2019年03月20日 星期三 10时28分59秒
 ************************************************************************/

#include<stdio.h>
#include<math.h>

#define Setup_list(name,...)\
    double *name##_list = (double []){__VA_ARGS__,NAN};\
    int name##_len = 0;\
    for(name##_len = 0;\
        !isnan(name##_list[name##_len]);\
       )name##_len++;

#define Length(in) in##_len

int main(){
    Setup_list(items,1,2,3,4,8);
    double sum = 0;
    for(double*ptr = items_list;!isnan(*ptr);ptr++)
        sum += *ptr;
    printf("total for items list[%d] :%g\n",Length(items),sum);
    return 0;
}
