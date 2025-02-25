#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
int main(){
    int fd[2];
    //fd[0]--> for reading 
    // fd[1]--> for writing
    if(pipe(fd)==-1){
        printf("failed to create p[ipe\n");
        return 1;
    }
    int id=fork();
    // fork() ko call krne pr child process create hota hain and file descripter bhi copy ho jate hai
    if(id==0){
        close(fd[0]);
        int n;
        printf("input a number\n");
        scanf("%d",&n);
        if(write(fd[1],&n,sizeof(int))==-1){// it return no. of bytes write on the pipe// it return no. of bytes write on the pipe
            printf("erroe to write\n");
            return 2;
        }
        close(fd[1]);
    }else{
        wait(NULL);// esa ho skta hai na ki phle parent aa jaye 
        close(fd[1]);
        int y;
        if(read(fd[0],&y,sizeof(int))==-1){
            printf("error to read from pipe\n");
        }
        close(fd[0]);
        printf("GOT FROM CHILD PROCESS :%d",y);
    }

    return 0;
}