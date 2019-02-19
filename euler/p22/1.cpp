/*************************************************************************
	> File Name: 1.cpp
	> Author:Gin.TaMa 
	> Mail:1137554811@qq.com 
	> Created Time: 2019年01月05日 星期六 13时58分06秒
 ************************************************************************/
#include <iostream>
#include <stdio.h>
#include <inttypes.h>
#include <algorithm>
#include "22.h"
 
int32_t main() {
    int64_t i = 0, len, sum, total = 0;
    while (nameList[i++].length() != 0) ;
    std::sort(nameList, nameList + i - 1);
    i = 0;
    while (nameList[i].length() != 0) {
        sum = 0;
        for (int32_t j = 0; j < nameList[i].length(); j++) {
            sum += nameList[i][j] - 'A' + 1;
        }
        total += sum * (++i);
    }
    printf("%"PRId64"\n", total);
    return 0;
}

 

