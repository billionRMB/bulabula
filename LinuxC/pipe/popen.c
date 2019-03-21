/*************************************************************************
	> File Name: popen.c
	> Author:Gin.TaMa 
	> Mail:1137554811@qq.com 
	> Created Time: 2019年02月22日 星期五 14时02分18秒
 ************************************************************************/
#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/wait.h>
#include<signal.h>

#define READ 0
#define WRITE 1

FILE* myPopen(const char* command,const char* mode){
    int pfp[2],pid;
    FILE * fp;
    int parent_end,child_end;

    if(* mode == 'r'){
        parent_end = READ;
        child_end = WRITE;
    }else if(* mode == 'w'){
        parent_end = WRITE;
        child_end = READ;
    }else return NULL;

    if(pipe(pfp) == -1)return NULL;

    if((pid = fork()) == -1){
        close(pfp[0]);
        close(pfp[1]);
        return NULL;
    }

    if(pid > 0){
        if ( close(pfp[child_end]) == -1 )
        return NULL;
        return fdopen(pfp[parent_end],mode);
    }

    close(pfp[parent_end]);
    dup2(pfp[child_end],child_end);
    close(pfp[child_end]);
    execl("/bin/sh","sh","-c",command,NULL);
    exit(1);
}

int main(){
    FILE *fp;
    char buf[100];
    int i = 0;
    fp=myPopen("who|sort","r");

    while(fgets(buf,100,fp)!=NULL){
        printf("%3d %s",i++,buf);
    }

    pclose(fp);
    return 0;
}
