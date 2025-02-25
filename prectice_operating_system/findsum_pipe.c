#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){
    int n;
    printf("input the size of aray\n");
    scanf("%d",&n);
    int arr[n];
    printf("enter the element of array\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int fd[2];
    if(pipe(fd)==-1){
        printf("failed to create to pipe\n");
        return 1;
    }
    int id=fork();
    if(id==-1){
        return 4;
    }
    if(id==0){
        close(fd[0]);
        int sum1=0;
        for(int i=0;i<n/2;i++){
            sum1+=arr[i];
        }
       if( write(fd[1],&sum1,sizeof(int))==-1){
        printf("erreo to write on the pipe\n");
        return 2;
       }
       printf("sum of half element : %d\n",sum1);
       close(fd[1]);
    }else{
        wait(NULL);
        close(fd[1]);
        int sum2=0;
        if(read(fd[0],&sum2,sizeof(int))==-1){
            printf("error to read from child process\n");
            return 3;
        }
        close(fd[0]);
        for(int i=n/2;i<n;i++){
            sum2+=arr[i];
        }
        printf("sum of array is :%d",sum2);
    }

    return 0;
}