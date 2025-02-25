#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
#include<semaphore.h>

sem_t semaphore;// mutex like variable

void* routine(){
    sem_wait(&semaphore);// is case m seaphore ki value 1 hai 
    // ydi semphorev ki value >0 hai than enter 
    // othrewise blocked
    // after entering value will become decrese
    // baaki thread block honge 
    sleep(1);// semaphore ka feel lene ke liye 
    printf("hello world\n");
    sem_post(&semaphore);// increment the value of semaphore
    // and wake up the blocked procesess

}

int main (int argc,char*agrv){
    pthread_t t[4];
    sem_init(&semaphore,0,1);
    // in case of multiple thread 2nd parameter is 0
    // in case of multiple process 2nd parameter is 1
    for(int i=0;i<4;i++){
        if(pthread_create(&t[i],NULL,&routine,NULL)!=0){
            printf("error to create thread\n");
        }
    }

    for(int i=0;i<4;i++){
        if(pthread_join(t[i],NULL)!=0){
            printf("failed to join thread\n");
        }
    }
    sem_destroy(&semaphore);
    return 0;

}