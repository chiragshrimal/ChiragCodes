#include<stdio.h>
#include<stdlib.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<signal.h>


// kill() send signal to another process
// signal() handle the signal with in the signal


// sigcount and sigstop using for manage the order vof process

int main(){
    int pid=fork();
    if(pid==-1){
        return 1;
    }
    if(pid==0){
        // child process
        while(1){
            printf("hello world\n");
            usleep(50000);
        }

    }else{
        //parent process
        kill(pid,SIGSTOP);// child process ko pause kar dega terminated nhi krta hai
        sleep(1);
        kill(pid,SIGCONT);
        sleep(1);
        kill(pid,SIGKILL);
        wait(NULL);
        
    }
    
    
    return 0;
}