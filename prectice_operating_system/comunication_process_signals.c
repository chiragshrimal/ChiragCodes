#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>
#include<time.h>
#include<signal.h>


// kill() send signal to another process
// signal() handle the signal with in the signal
// process comunicate using signals but in signal we can not transfer data

void handler_sigusr1(int sig){// these are atomic operation 
    printf(" (hin) remember that multiplication is repetative addition !\n");
}
int main(){
    int id=fork();
    if(id==-1){
        return  1;
    }
    if(id==0){
        // child process
        sleep(5);
        //kill(getppid(),SIGKILL);// after 5 second apne parent ko kill kar dega 
        kill(getppid(),SIGUSR1);// for terminate the p[arent process
        //parent process terminate ha jata hai

    }else{
        // parent process
        signal(SIGUSR1,&handler_sigusr1);
        int x;
        printf("enter a number\n");
        scanf("%d",&x);
        if(x==15){
            printf("right\n");
        }else{
            printf("wrong\n");
        }
        wait(NULL);
    }
}