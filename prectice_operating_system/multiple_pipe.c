#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<time.h>

int main(int argc, char*argv[]){
    int fd[3][2];
    for(int i=0;i<3;i++){
        if(pipe(fd[i])==-1){
            return 1;
        }
    }
    int pid1=fork();
    if(pid1<0){
        return 2;
    }
    if(pid1==0){
        close(fd[0][1]);
        close(fd[1][0]);
        close(fd[2][0]);
        close(fd[2][1]);
        int x;
        if(read(fd[0][0],&x,sizeof(int))<0){
            return 3;
        }
        x+=5;
        if(write(fd[1][1],&x,sizeof(int))<0){
            return 4;
        }
        close(fd[0][0]);
        close(fd[1][1]);
        return 0;
    }
    int pid2=fork();
    if(pid2<0){
        return 5;
    }
    if(pid2==0){
        close(fd[0][1]);
        close(fd[1][1]);
        close(fd[0][0]);
        close(fd[2][0]);
        int x;
        if(read(fd[1][0],&x,sizeof(int))<0){
            return 3;
        }
        x+=5;
        if(write(fd[2][1],&x,sizeof(int))<0){
            return 4;
        }
        close(fd[1][0]);
        close(fd[2][1]);
        return 0;
    }
    // parent process
        close(fd[0][0]);
        close(fd[1][1]);
        close(fd[1][0]);
        close(fd[2][1]);
        int x;
        printf("input a number");
        scanf("%d",&x);
        if(write(fd[0][1],&x,sizeof(int))<0){
            return 3;
        }
        if(read(fd[2][0],&x,sizeof(int))<0){
            return 4;
        }
        printf("result is :%d",x);
        close(fd[1][0]);
        close(fd[2][1]);
        waitpid(pid1,NULL,0);
        waitpid(pid2,NULL,0);
        return 0;
}