#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<time.h>
#include<unistd.h>

// kisi specific child ke terminate hone tak ke wait k liye 
// simple wait() function wo process kop define nhi kryta hain 
// jo bhi child phle khtm ho jayega usi ka maan leta hai 
// waitpid bhi child ki process id return krta hai  

int main(int argc,char*argv[]){
    int pid1=fork();
    if(pid1==-1){
        printf("error creating process");
        return 1;
    }
    if(pid1==0){
        sleep(4);
        printf("finished execution of child 1 :%d\n",getpid());
        return 0;
    }
    int pid2=fork();
    if(pid2==-1){
        return 3;
    }
    if(pid2==0){
        sleep(1);
        printf("finished execution of child 2 :%d\n",getpid());
        return 0;
    }
    //parent process
    // wait(NULL);
    // printf("waited for %d\n",pid2);
    // wait(NULL);
    // printf("waited for %d\n",pid1);

    waitpid(pid1,NULL,0);// ab yha toh phle 4 second wait krna hi pdega 
    printf("waited for %d\n",pid1);
    waitpid(pid2,NULL,0);
    printf("waited for %d\n",pid2);





    }