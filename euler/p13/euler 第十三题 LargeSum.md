### euler 第十三题 LargeSum

题目描述就不多说了 附上链接 [euler p13](http://pe-cn.github.io/13/)

类型上是大整数加法

我们用char数组存储每个位上的值，累加后，再处理进位就好

就是模拟进位的一个过程

不过有几点需要注意的是

1. 100 个数相加最多进几位 或者说 100个n位的相加最大会变成n + ？位的结果

   ​	答案是 n + 2 位 

   为啥呢 ？ 假如 都是 9999...... * 100 也就 多两位，就是说考虑极端情况下，每个数字都是n位里最大的

   9999....... 100 个相加，也就多两位，所以 答案是 n + 2 ,如果是1000个相加 那就是 n + 3 ，懂了不

2. 如果用字符串来储存一个数字读入的时候，index 为 0 的位置的对应的值是原数字里最高的位数

   ​	比如 说 把 521 读入到 string里 会变成 

   | 0    | 1    | 2    | 3    |
   | ---- | ---- | ---- | ---- |
   | ‘5’  | ‘2’  | ‘1’  | \0   |

   ​	但是呢 ，存答案的那个int数组需要留下进位的空位的也就是说，index = 0 代表最低位，这样才能留下进位的空间

   | 0    | 1    | 2    | 3                       |
   | ---- | ---- | ---- | ----------------------- |
   | 1    | 2    | 5    | // 留着存放进位后的数字 |

   好了大体上没有别的需要注意的了

   在下面的程序里 ans[0] 代表的答案的长度


```c
/*************************************************************************
	> File Name: 1-test.c
	> Author:Gin.TaMa 
	> Mail:1137554811@qq.com 
	> Created Time: 2018年12月20日 星期四 23时48分08秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
int main(){
    int ans[55] = {0};// ans[0] 用来保存 ans 的长度的
    char num[55];//记得下次改一下名字 为 input_num 不然容易和ans乱掉
    while(scanf("%s",num)!= EOF){
        int num_len = strlen(num);
        //if(ans[0] < num_len) ans[0] = num_len;
        (ans[0] < num_len) && (ans[0] = num_len);
        for(int i = 1;i <= num_len;i ++){ // 注意此次如果没有先用strlen则可以使用; num[i];作为循环的判断条件 在循环string里的时候是个小技巧
            ans[i] += num[num_len - i] - '0';//因为string里0对应的是最高位上的数字 需要处理一下
        }
        for(int i = 1;i <= ans[0];i ++){
            if(ans[i] < 10) continue;
            ans[i + 1] += ans[i]/10;
            ans[i] %= 10;
            ans[0] += (i == ans[0]);//如果最高位大于0 即会进位，ans【0】需要加1
        }
    }
    printf("%d\n",ans[0]);
    for(int i = 0;i < 10;i++){
        printf("%d",ans[ans[0]-i]);
    }
    printf("\n");
}
```

这个同时可以作为大整数加减乘除的框架

下面的那个是简化版的一个 少了一半的运算

```c
/*************************************************************************
	> File Name: 1-test.c
	> Author:Gin.TaMa 
	> Mail:1137554811@qq.com 
	> Created Time: 2018年12月20日 星期四 23时48分08秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
int main(){
    int ans[55] = {0};
    char num[55];//记得下次改一下名字 为 input_num 不然容易和ans乱掉
    while(scanf("%s",num)!= EOF){
        int num_len = strlen(num);
        //if(ans[0] < num_len) ans[0] = num_len;
        (ans[0] < num_len) && (ans[0] = num_len);
        for(int i = 1;i <= num_len;i ++){ // 注意此次如果没有先用strlen则可以使用; num[i];作为循环的判断条件 在循环string里的时候是个小技巧
            ans[i] += num[num_len - i] - '0';//因为string里0对应的是最高位上的数字 需要处理一下
        }
    }
    // 这里可以把进位的放在最外面 ,因为100个数相加 最多进两位也就是说ans[i]/10;不会超过1000,int是可以存储下的，再然后总共只用处理一次进位
    for(int i = 1;i <= 52;i ++){
        if(ans[i] < 10)continue;
        ans[i+1] += ans[i]/10;
        ans[i] %= 10;
    }
    for(int i = 0;i < 10;i++){
        printf("%d",ans[52-i]);
    }
    printf("\n");
}
```

好了 ，最近在做euler上面的题，csp啥的就没碰，等学完euler就刷掉那些csp的题去