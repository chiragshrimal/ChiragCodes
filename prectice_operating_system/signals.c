#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<time.h>
#include<signal.h>

int main(){
    int id=fork();
    if(id==-1){
        printf("erroe to create child process\n");
        return 1;
    }
    if(id==0){
        // child process
        while(1){
            printf("some teyxt file\n");
            usleep(50000);// microsecond ke liye sleep krega 
        }
    }else{
        // parent process
        sleep(1);
        kill(id,SIGKILL);// send signal to proces which process id =id
        // and terminatet the that process wo kesi bhi state m ho
        // yha id ka matlab 0 nhi hai 
        // jab child process create hota hai tab parent ke id variable m child ki process id ko dal deta hai 
        wait(NULL);
    }
    printf("hello");// yha per ye ek bar hi execute hoga by parent process
    return 0;


}