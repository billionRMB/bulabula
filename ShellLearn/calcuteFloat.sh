#!/bin/bash
#处理小数运行的函数
function calFloat(){
    str=$1
    printf "%0.2f\n" `echo "scale=2 ; $str"|bc` 
}

#用法
a=80
b=100
calFloat "2/3"
calFloat "$a*$b"
calFloat "$a/$b"
#awk计算
a=10
b=20
echo $a $b | awk '{printf("%0.2f\n",$1*$2)}'
#bc计算
echo "scale=2;$a*$b"|bc
