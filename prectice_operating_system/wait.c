#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
// if we dont use wait() function then 
// generate output dependes on compiler randomly generate
// agr hme particular kisi order m output chahiye then we use wait() function 
int main(int argc,char*argv[]){
    int id=fork();
    int n;
    if(id==0){
        n=1;
    }else{
        n=6;
    }
    if(id!=0){
        wait(NULL);// parent process tab tak wait krega jab tak child process complete na ho jaye******
    }
    for(int i=n;i<n+5;i++){
        printf("%d",i);
        fflush(stdout);// for immediate output
    }
    if(id!=0)
    printf("\n");
    return 0;
}