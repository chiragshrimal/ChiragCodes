#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<time.h>
// agrument pass throw top thread

int primes[5]={2,3,5,7,11};

void* routine(int *arg){
    int index=*arg;
    printf("%d ",primes[index]);
    free(arg);
}
int main(int argc,char*argv[]){
    pthread_t t[5];
    for(int i=0;i<5;i++){
        int *a=malloc(sizeof(int));
        *a=i;
        if(pthread_create(&t[i],NULL,&routine,(int*)a)!=0){// ydi yha se i ka direct address bhejte hai toh 
        // won bar bar change ho rha hai 
        // toh usme dikkatv aayegi 
            printf("error to create new thread\n");
            return 1;
        }
    }

      for(int i=0;i<5;i++){
        if(pthread_join(t[i],NULL)!=0){
            printf("failed to join thread\n");
            return 2;
        }
    }

    return 0;
}