#include<stdio.h>
#include<stdlib.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main(int argc ,char*argv[]){
    // 5=> 5*4=20=>20
    int fd1[2];//p=>c
    int fd2[2];// c=>p
    if(pipe(fd1)==-1){// pipe one 
        printf("faild to create pipe one\n");
        return 1;
    }
    if(pipe(fd2)==-1){// pipe two
        printf("faild to create pipe two\n");
        return 1;
    }
    int id=fork();
    if(id==-1){
        printf("failed to create child process\n");
        return 2;
    }
    if(id==0){
        // child process
        sleep(1);// wait for 1 sec to parent to write to the pipe
        int n;
        close(fd1[1]);
        close(fd2[0]);
        if(read(fd1[0],&n,sizeof(int))==-1){
            printf("error to read from pipe\n");
            return 1;
        }
        printf("received :%d\n",n);
        int x;
        printf("enter a number to multiply it\n");
        scanf("%d",&x);
        n=n*x;
        if(write(fd2[1],&n,sizeof(int))==-1){
            printf("erroe towrite on p[ipe two\n");
            return 2;
        }
        printf("wrote :%d\n",n);
        close(fd1[0]);
        close(fd2[1]);
    }else{
        //parent process
        close(fd1[0]);
        close(fd2[1]);
        int n;
        printf("enter a number\n");
        scanf("%d",&n);
        if(write(fd1[1],&n,sizeof(int))==-1){
            printf("error tom write on pipe\n");
            return 4;
        }
        wait(NULL);// wait for child to die 
        int x;
        if(read(fd2[0],&x,sizeof(int))==-1){
            printf("erreo to nread from pipe two\n");
            return 5;
        }
        printf("result is :%d\n",x);
        close(fd1[1]);
        close(fd2[2]);
        }
        return 0;
}