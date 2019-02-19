## Shell 中小数运算的问题

在bash 中进行小数的运算是一件有点麻烦的事情。

一般的解决办法有：

#### 方法－：AWK

```bash
a=10
b=20
echo $a $b | awk '{printf("%0.2f",$1*$2)}'
```

啥意思呢，就是使用echo 拼凑一个String  : 10 20  然后用awk 切分后借助awk自带的东西进行运算

可以解决问题

#### 方法二：BC

注意定义scale=2代表小数点位数，为零的话就不会进行小数运算了。。

```bash
echo "scale=2;$a*$b"|bc
```

实质是是拼凑了一个scale=2;10*20的一个String 来交给bc来运算。

#### 封装一下。。

那么我们封装一下这个过程好不

```bash
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
```

我们自己拼一个待计算的表达式然后交给bc，使用起来十分简单。

