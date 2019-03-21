## Socket Linux c 学习小结(一)

一、背景

​	初次接触服务器与客户端的知识，先从最简单的做起：了解linux中使用的计算器。linux中使用的计算器是最为简单的服务器与客户端协同工作的例子。

二、从管道到服务器与客户端

​	传统的Unix管道只是单方向的传送数据。打个比方，在linux命令行下使用cat /etc/passwd | grep Jack命令。这个命令将cat的输出结果通过管道传送到grep命令的标准输入中。但这只是一个单向的数据传送，grep的输出结果并不会进行回传。而若有两个进程A、B，他们两个协同进行工作，A进程将其输出结果传送给B进程，B进程处理数据完毕后再返回给A进程。这样，它们之间并不是单向的管道，而是一个双向的管道。B对A提供服务，而A是B的客户。A就叫做客户端，B叫做服务器.

----

补充

创建匿名管道的系统调用:

```c
#include<unistd.h>
int pipe(int pipefd[2]);
```

匿名管道：**单向**的数据传送通道

pipefd[2] 为两端的文件描述符，需要注意的是，由于文件描述符只在进程的范围内有意义，换到另一个进程后就不再指向同一个文件了，所以，匿名管道两端的进程需要有相同的祖先：从而另它们的文件描述符指向同一个文件。

---

#### 练习：

​	一个简易版的bc 命令的实现 

​	其实吧

​	bc 这个命令是把用户的输入进行解析，变成后缀表达式，然后借助 dc 这个命令去处理运算。

```c
/*************************************************************************
	> File Name: tinyBc.c
	> Author:Gin.TaMa 
	> Mail:1137554811@qq.com 
	> Created Time: 2019年02月22日 星期五 10时17分53秒
 ************************************************************************/

#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/wait.h>

#define oops(m,x) {perror(m);exit(x);}
void be_dc(int*,int*);
void be_bc(int*,int*);
int main(){
    int pid ,todc[2],fromdc[2]; /*equipmet*/

    /* make two pipes */
    
    if(pipe(todc) == -1||pipe(fromdc) == -1){
        oops("pipe failed",1);
    }
    
    /* get a process for user inerface */

    if((pid = fork()) == -1) {
        oops("cannot fork",2);
    }

    if(pid == 0){
        be_dc(todc,fromdc);
    }else{
        be_bc(todc,fromdc);
        wait(NULL);
    }

    return 0;
}

/* 
 * set up stdin and stdou,then execl dc
 */
void be_dc(int* in,int* out){
    /* setup stdin from pipein */
    if(dup2(in[0],0) == -1){
        oops("dc:cannot redirect stdin",3);
    }
    close(in[0]);
    close(in[1]);
    /* setup stdout to pipeout */
    if(dup2(out[1],1) == -1){
        oops("dc:cannot redirect stdout",4);
    }
    close(out[1]);
    close(out[0]);
    /* now execl dc with the - option */
    execlp("dc","dc","-",NULL);
    oops("cannot run dc",5);
}
void fatal(char * mess){
    fprintf(stderr,"err: %s\n",mess);
    exit(1);
}
void be_bc(int * todc,int * fromdc){
    int num1,num2;
    char operation[BUFSIZ],message[BUFSIZ],* fgets();
    FILE *fout,*fpin,*fopen();

    /* setup */
    close(todc[0]);
    close(fromdc[1]);
    fout = fdopen(todc[1],"w");
    fpin = fdopen(fromdc[0],"r");
    while(printf("tinyBc: "),fgets(message,BUFSIZ,stdin)!=NULL){
        if(sscanf(message,"%d%[-+*/^]%d",&num1,operation,&num2)!=3){
            printf("syntax error\n");
            continue;
        }
        if(fprintf(fout,"%d\n%d\n%c\np\n",num1,num2,*operation)==EOF){
            fatal("Error writing");
        }
        fflush(fout);
        if(fgets(message,BUFSIZ,fpin)==NULL){
            break;
        }
        printf("%d %c %d = %s",num1,*operation,num2,message);
        
    }
    fclose(fout);
    fclose(fpin);

}
```

上述程序的工作流程

```c
		+----------+               +--------+
stdin > 0         >==pipetodc======>        |
		|	tinybc |               |   dc - |
stdout< 1         <===pipefromdc===<        |
        +----------+               +--------+
```

值得学习的地方：

1. main 函数的封装

   ```c
   ...
       /* get a process for user inerface */
       if((pid = fork()) == -1) {
           oops("cannot fork",2);
       }
   
       if(pid == 0){
           be_dc(todc,fromdc);
       }else{
           be_bc(todc,fromdc);
           wait(NULL);
       }
   ...
   ```

   和  if ( (pid = fork()) == -1) 的使用

   即　保留了Pid ，并　利用( )  == -1 来进行函数调用结果的判断

2. 调用系统shell 的方式

   `execlp("dc","dc","-",NULL);`

   补充:

   ---

   #### 系统调用 exec() 组

   ```c
   int execve(const char* filename, char* const argv[], char* const envp[]);
   ```

   这个函数将在 <strong>现在运行的</strong> 进程中以<code>argv</code>中存储的字符串为参数 来运行由<code>filename</code>指向的可执行程序，并将<code>envp</code>中存储的“变量=数值”对作为环境变量代入这个程序。

   根据传统，<code>argv</code>中的第一个参数必须与<code>filename</code>一致，**真正的参数从第二个开始**。<code>execve</code>会以<code>filename</code>的程序覆盖现在进程中正在运行的程序，**因此所有在<code>execve</code>函数之后的行都只会在<code>execve</code>失败之后被执行**，

   所以我们可以通过在后面加入打印语句等方法标识<code>execve</code>运行失败。

   <p>基于<code>execve()</code>的还有六个函数；他们都具有在现有的进程中打开某一可执行文件、覆盖现有程序执行的功能。</p>

   ```c
   int execl(const char* path, const char* arg, ...);
   int execlp(const char* file, const char* arg, ...);
   int execle(const char* path, const char* arg,
              ..., char* const envp[]);
   int execv(const char* path, char* const argv[]);
   int execvp(const char* file, char* const argv[]);
   int execvpe(const char* file, char* const argv[],
               char* const envp[]);
   ```

   我们可以将这些函数表示为：“exec + l/v + p/e/pe”，
   这六个函数主要有两处不同。

   ​	第一处不同（l/v）在参数中表现为“execl<em>”类函数**将所有参数作为一整个字符串代入**</em>，看函数原型也可以看出来，这是个变参函数。而“execv”类函数将参数分别放入一个字符串的数组中，将数组作为参数代入函数运行。

   ​	第二处不同（p/e/pe）表现为**包含 p（代表 path）的函数可以模仿计算机中壳的功能，在“file”中不含“/”时应用环境变量 PATH 中的目录来寻找可执行文件**，而包含 e（代表 environment）的函数可以像<code>execve</code>一样将“变量=数值”对作为环境变量代入程序。

   ---

   execlp 就很好理解了: exec + l + p 

3. fdopen 函数的使用:

   fdopen取一个现存的文件描述符（我们可能从 open，dup，dup2，fcntl，pipe，socket，socketpair或accept函数得到此文件描述符） ，并使一个标准的I/O流与该描述符相结合。所以，该函数常用于由创建管道和网络通信通道函数获得的描述符。

4. sscanf(message,"%d%[-+*/^]%d",&num1,operation,&num2)!=3 　

   ---

   补充：

   这个函数的用法：

   **sscanf与scanf类似，都是用于输入的，只是后者以键盘(stdin)为输入源，前者以固定字符串为输入源。**

   第二个参数可以是一个或多个 {%[*] [width] [{h | I | I64 | L}]type | ' ' | '\t' | '\n' | 非%符号}

   **注：**

   1、 * 亦可用于格式中, (即 %*d 和 %*s) 加了星号(*) 表示跳过此数据不读入. (也就是不把此数据读入参数中)

   2、{a|b|c}表示a,b,c中选一，[d],表示可以有d也可以没有d。

   3、width表示读取宽度。

   4、{h | l | I64 | L}:参数的size,通常h表示单[字节](https://baike.baidu.com/item/%E5%AD%97%E8%8A%82)size，I表示2字节 size,L表示4字节size(double例外),l64表示8字节size。

   5、type :这就很多了，就是%s,%d之类。

   6、特别的：%*[width] [{h | l | I64 | L}]type 表示满足该条件的被过滤掉，不会向目标参数中写入值

   失败返回0 ，否则返回格式化的参数个数

   7、如果读取的字符串，不是以空格来分隔的话，就可以使用%[]。

   函数将返回成功赋值的字段个数；返回值不包括已读取但未赋值的字段个数。 返回值为 0 表示没有将任何字段赋值。 如果在第一次读取之前到达字符串结尾，则返回EOF。

   如果buffer或format是NULL调用指针，无效参数处理程序，如中所述参数验证。 如果允许继续执行，则这些函数返回 -1 并将errno设置为EINVAL。

   成功则返回参数数目，失败则返回-1，错误原因存于[errno](https://baike.baidu.com/item/errno)中。