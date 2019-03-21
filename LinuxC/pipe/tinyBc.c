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
