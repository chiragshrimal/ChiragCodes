#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
int main(){
    //5=>5*4=>20=>20
    int fd[2];
    pipe(fd);
    int id=fork();
    if(id==-1){
        printf("an erroe occured with fork\n");
        return 1;
    }
    if(id==0){
        close(fd[0]);
        int x;
        printf("input a number: ");
        scanf("%d",&x);
        write(fd[1],&x,sizeof(int));
        close(fd[1]);
    }else{
        close(fd[1]);
        int y;
        read(fd[0],&y,sizeof(int));
        y=y*4;
        close(fd[0]);

    }
}