#include<stdio.h>
#include<stdlib.h>
#include<unistd.h> // for system call in linux system specific library 
// ajb bhi hm fork() ko call krte hai toh chid process created hota hai use alg memory milti hai or
// same program wo bhi run krta hai ydio ek m vakue change hoti hai toh dusre par koi frk nhi pdta 
int main(int argc,char*argv[]){
    int id=fork();// child process created
    // child process id ==0;
    if(id==0){
        printf("hello from child process\n");
    }else{
        printf("hello from parent process\n");
        fork();
    }
    printf("HELLO WORLD\n");
    return 0;
}