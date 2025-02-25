#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<pthread.h>

int fuel=50;
pthread_mutex_t mutexFuel;
pthread_mutex_t mutexWater;

void* routine(){

    pthread_mutex_lock(&mutexFuel);
    pthread_mutex_lock(&mutexWater);
    fuel+=50;
    printf("increment in fuel is:%d",fuel);
    pthread_mutex_unlock(&mutexWater);
    pthread_mutex_unlock(&mutexFuel);
    // phli bar mutex lgane se mutex change 
    // dusre mutex m nhi ghus payega
    /*pthread_mutex_lock(&mutexFuel);
    pthread_mutex_lock(&mutexFuel);
    fuel+=50;
    pthread_mutex_unlock(&mutexFuel);
    */


   // yha bhi deadlock ho skta hain
   // premtion krke ho skta hai
   // because mutex ka different different order hai
   /*if(rand()%2==0){
    pthread_mutex_lock(&mutexFuel);
    pthread_mutex_lock(&mutexWater);
   }else{
     pthread_mutex_lock(&mutexWater);
    pthread_mutex_lock(&mutexFuel);
   }
   fuel+=50;
   printf("increment in fuel is:%d\n",fuel);
   pthread_mutex_unlock(&mutexFuel);
   pthread_mutex_unlock(&mutexWater);
   */

}

int main(int argc, char*argv[]){
    pthread_t t[8];
    pthread_mutex_init(&mutexFuel,NULL);
    pthread_mutex_init(&mutexWater,NULL);

    for(int i=0;i<8;i++){
    if(pthread_create(&t[i],NULL,&routine,NULL)!=0){
        printf("error to create thread\n");
    }
    }
    for(int i=0;i<8;i++){
    if(pthread_join(t[i],NULL)!=0){
        printf("failed to join thread");
    }
    }
    pthread_mutex_destroy(&mutexFuel);
    pthread_mutex_destroy(&mutexWater);
    return 0;
}