#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

// situation where in multiple process tries to exess 
// the shared resourses
// called race condition
// using lock variable solving race  condition problem 
// but mutual exlcution is not gureenteed
// so mutual exlution ko guireenteed krne ke liye pthread_mutex ka use krte hai 
// but isme bhi bounded waiting also not gureenteed
int x=0;
//int lock=0;
pthread_mutex_t mutex;
void* routine(){
    for(int i=0;i<1000000;i++){
        // if(lock==1){
        //     //wait for lock==0
        //     while(lock!=0);
        // }
        pthread_mutex_lock(&mutex);// atomic instruction // in instructiuon ke beech m se preemtion nhi kr skte 
        //lock=1;
        x++;// critical section 
        //lock=0;
        pthread_mutex_unlock(&mutex);// atomic instruction 
    }
}
// void* routine2(){
//     x++;
//     printf("valu of x is:%d\n",x);
// }


int main(){
    pthread_t t1,t2;
    pthread_mutex_init(&mutex,NULL);
    if(pthread_create(&t1,NULL,&routine,NULL)!=0){
        printf("error to create new thread\n");
        return 1;
    }
     if(pthread_create(&t2,NULL,&routine,NULL)!=0){
        printf("error to create new thread\n");
        return 1;
    }
    if(pthread_join(t1,NULL)!=0){
        return 3;
    }
     if(pthread_join(t2,NULL)!=0){
        return 3;
    }
    pthread_mutex_destroy(&mutex);
    printf("value of x is:%d",x);// expected ans 2000000  aana chahiye tha 
    return 0;
}