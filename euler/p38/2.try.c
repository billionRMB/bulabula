/*************************************************************************
	> File Name: 2.try.c
	> Author:Gin.TaMa 
	> Mail:1137554811@qq.com 
	> Created Time: 2019年01月10日 星期四 15时01分11秒
 ************************************************************************/

#include<stdio.h>
#include<math.h>

#define max 10000

#define p(n){\
    printf("%s %d\n",#n,n);\
}

int ans[10] = {0};

int is_vaild(int n,int * num){
    int tempn[10] = {0};
    for(int i = 1;i < n;i ++){
        int temp = i * n;
        int lengh = pow(10,floor(log10(temp)));
        while(lengh){
            if(temp / lengh == 0)return 0;
            if(tempn[temp / lengh]==1)return num[0] == 9; 
            num[++num[0]] = temp/lengh;
            tempn[temp / lengh] = 1;
            temp %= lengh;
            lengh /= 10;
        }
    }
}

int cmp(int * ans,int *temp){
    int i;
    int flag = 0;
    for(i = 1;i < 10 ;i ++){
        if(ans[i] > temp[i]){
            flag = 0;
            break;
        }else if(ans[i] < temp[i]){
            flag = 1;
            break;
        }
    }
    if(flag){
        for(int i = 1;i < 10;i ++){
            ans[i] = temp[i];
        }
    }
}

void pn(int * num){
    for(int i = 1; i < 10;i ++){
        printf("%d",num[i]);
    }
    printf("\n");
}

int main(){
    for(int i = 1;i < max ;i++){
        int temp[10] = {0};
        if(!is_vaild(i,temp))continue;
        p(i);
        cmp(ans,temp);
    }
    pn(ans);
    return 0;
}
