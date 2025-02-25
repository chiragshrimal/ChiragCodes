#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>
#include<pthread.h>

int primes[10]={2,3,5,7,11,13,17,19,23,29};

// ydi hm sum ko global declare krenge than race condition ki dikkat aa skti hai

void* routine(int *arg){
    int index=*arg;
    int sum=0;
    for(int i=0;i<5;i++){
        sum+=primes[index+i];
    }
    *arg=sum;
    return arg;

}
int main(int argc,char*argv[]){
    pthread_t t[2];
    for(int i=0;i<2;i++){
        int* a=malloc(sizeof(int));
        *a=i*5;
        if(pthread_create(&t[i],NULL,&routine,a)!=0){
            printf("error to create new thread\n");
            return 1;
        }
    }
    int totalsum=0;
      for(int i=0;i<2;i++){
        int *r;
        if(pthread_join(t[i],&r)!=0){
            printf("failed to join thread\n");
            return 2;
        }
        totalsum+=*r;
        free(r);
    }
    printf("%d",totalsum);

    return 0;
}