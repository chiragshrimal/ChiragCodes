#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

// same process can have multiple thread
//  threads are shared same memory of address space
// all threads have independent stack,register set
// saare variable like local , global, sttic sab share hote hai 
// in below code u can seen process id dfono ki dame print hopgi 
// but in case of thread critical section ki problem aa skti hai 
// because same share memory ka use hota haio unlike the process using fork()
int x=2;
void* routine(){
    x++;
    sleep(2);
    printf("process id %d\n",getpid());
    printf("the value of x is:%d\n",x);
}
void* routine2(){
    sleep(2);
    printf("process id %d\n",getpid());
    printf("the value of x is:%d\n",x);
}


int main(int argc,char*argv[]){
    pthread_t t1,t2;
    if(pthread_create(&t1,NULL,&routine,NULL)!=0){
        return 1;
    }
    if(pthread_create(&t2,NULL,&routine2,NULL)!=0){
        return 2;
    }

    if(pthread_join(t1,NULL)!=0){
        return 4;
    }
    if(pthread_join(t2,NULL)!=0){
        return 5;
    }

    return 0;


}