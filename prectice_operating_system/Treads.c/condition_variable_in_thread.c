#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>
#include<pthread.h>


int fuel=0;
pthread_mutex_t mutex;
pthread_cond_t condfuel;// conditio variable 
void* fuelfilling(){
    for(int i=0;i<5;i++){
        pthread_mutex_lock(&mutex);
        fuel+=15;
        printf("fuel is %d\n",fuel);
        pthread_cond_signal(&condfuel);
        // send signal to waited thread process
        pthread_mutex_unlock(&mutex);
        sleep(1);
    }

}
void* car(){
    pthread_mutex_lock(&mutex);
    while(fuel<40){// agr while loop m pthread_cont_wait nhi dala thop dedlock ho jayega ;
        printf("no fuel.waiting\n");
        pthread_cond_wait(&condfuel,&mutex);
        // like pthread_mute_unlock() function ki trh kaam krta hain 
        //and wait for the signal 
        // after wait is complete call function like  pthread_mutex_lock(&mutex);
    }
    fuel-=40;
    printf("got fuel , left fuel is :%d",fuel);
    pthread_mutex_unlock(&mutex);

}

int main(int argc ,char*argv[]){
    pthread_t t[2];
    pthread_mutex_init(&mutex,NULL);
    pthread_cond_init(&condfuel,NULL);
    for(int i=0;i<2;i++){
        if(i==1){
            if(pthread_create(&t[i],NULL,&fuelfilling,NULL)!=0){
                printf("erroe to create thread\n");
            }
        }else{
            if(pthread_create(&t[i],NULL,&car,NULL)!=0){
                printf("error to create thread\n");
            }
        }
    }

    for(int i=0;i<2;i++){
        if(pthread_join(t[i],NULL)!=0){
            printf("failed to join \n");
        }
    }
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&condfuel);
    
    return 0;
}