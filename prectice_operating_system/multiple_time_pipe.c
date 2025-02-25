#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<time.h>


// hme "n" process create  krne hai
// no. of pipe is =n+1
// cycle bnni chahiye 

#define n 3
int main(int argc,char*argv[]){
    int pid[n];
    int fd[n+1][2];
    for(int i=0;i<n+1;i++){
        if(pipe(fd[i])<0){
            printf("error to create the pipe\n");
            return 1;
        }
    }
    for(int i=0;i<n;i++){
        pid[i]=fork();
        if(pid[i]<0){
            printf("error to create new child\n");
            return 2;
        }
        if(pid[i]==0){
            
            for(int j=0;j<n+1;j++){
                if(i!=j){
                    close(fd[j][0]);
                }
                if(i+1!=j)
                close(fd[j][1]);

            }
            int x;
            if(read(fd[i][0],&x,sizeof(int))<0){
                printf("error to write\n");
                return 3;
            }
            x++;
            if(write(fd[i+1][1],&x,sizeof(int))<0){
                printf("error nto write\n");
                return 4;
            }
            close(fd[i][0]);
            close(fd[i+1][1]);
            return 0;// taki ek process ek hi process create kre 
        }
    }
        // parent process
        int y;
        printf("enter a number\n");
        scanf("%d",&y);
        if(write(fd[0][1],&y,sizeof(int))<0){
            printf("error to write\n");
            return 5;
        }
        if(read(fd[n][0],&y,sizeof(int))<0){
            printf("error to read\n");
            return 6;
        }
        printf("result is :%d",y);
        close(fd[0][1]);
        close(fd[n][0]);
        for(int i=0;i<n;i++){
            wait(NULL);
        }

}