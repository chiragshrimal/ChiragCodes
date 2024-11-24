#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<sys/syscall.h>

// thread execute a function routine 
void* routine(){
    printf("test for thread\n");
    sleep(3);
    printf("ending the thread\n");
    pthread_t th=pthread_self();
    // like id but at pthread level api 
    printf("%ul\n",th);// id at the pthread level 
    printf("%d\n",gettid());//gettid() for get thread id in the  operating system 

}

int main(){
    pthread_t t1,t2;
    // pthread_t is the data type of the pthread library 
    // t1 is the thread id 
    // it can be a unsigned long long or unsigned long 
    if(pthread_create(&t1,NULL,&routine,NULL)!=0){
        printf("error to create new thread\n");
        return 1;
    }
    if(pthread_create(&t2,NULL,&routine,NULL)!=0){
        printf("erroe to execution to create new thread\n");
        return 2;
    }
    // pthread_create create thread and start execution of  rouotine function

    // pthread_create m 1st parameter for address of thread 
    //2. NULL
    //3. jis function ko execute krta hai
    // 4. jis function kop execute krna hai uske parameter
     if(pthread_join(t1,NULL)!=0){
        return 4;
     }
     if(pthread_join(t2,NULL)!=0){
        return 5;
     }
    // pthread_join is used for wait for teminate the thread which thread id is t1;
    // and terminate hone par saare ka saara resourse waps le leta hai thread se 
    // or program parent ke pass chla jata hai 
    // agr hme thread crate krna hai toh above teen chijo ka use krna hoga 
    printf("HELLO\n");
    // last printf statement only print by parent process



    return 0;

}