#include<stdio.h>
#include<stdlib.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

// always remember that first child process terminated and after parent process terminated 
// otherwise memory leakage ki problem aa skti hai 
int main(int argc ,char*argv[]){
    int id=fork();// either return 0 or -1
    // in case of 0 succesful creation of new process
    // otherwise -1 for error

    //if we want first parent and after child tab mujhe sleep() krna pdega 
    if(id==0){
        sleep(1);
    }
    printf("current_id : %d , parent_id :%d \n",getpid(),getppid());
    // important 
    // ho skta hai ki parent proces child se phle hi terminate ho jaye
    // us case m chid ko ek new parent proces id milegi 
    // or memory leak ho skti hai 
    // isse bchne ke liye wait ka user krna pdega 

    // hm ese bhi likh skte hai ya fir 
    // if(id!=0){
    //     wait(NULL);
    // }
    // wait(NULL); // we can add directly otherwise for more specific
    int res=wait(NULL);
    if(res==-1){
        printf("no children to wait for\n");
    }else{
        printf("%d finished execution\n",res);
    }
    return 0;
}