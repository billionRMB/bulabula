/*************************************************************************
	> File Name: staticBug.c
	> Author:Gin.TaMa 
	> Mail:1137554811@qq.com 
	> Created Time: 2019年03月20日 星期三 14时46分40秒
 ************************************************************************/

#include<stdio.h>

char* aToA(char a){
    static char A;
    A = a + 'A' - 'a';
    return &A;
}

void test(char* a){
    printf("a = %c\n",*a);
    // 没有改变a的注意
    char* b = aToA('b');
    printf("a = %c ; b = %c\n",*a,*b);
    // a的值改变了
}

int main(){
    char* a = aToA('a');
    printf("a = %c\n",*a);
    test(a);
    return 0;
}
