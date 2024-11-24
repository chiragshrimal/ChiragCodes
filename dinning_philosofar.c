#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>

sem_t chopstick[5]; // each mutex represents one chopstick
void *philosopher(void *arg){
    int n = *(int *)arg; //dereferenced to fetch the philosopher's number
    printf("Philosopher %d wants to eat.\n", n);
    printf("Philosopher %d tries to pick left chopstick.\n", n);
    sem_wait(&chopstick[n]);
    printf("Philosopher %d picks the left chopstick.\n", n);
    printf("Philosopher %d tries to pick right chopstick.\n", n);
    sem_wait(&chopstick[(n+1)%5]);
    printf("Philosopher %d picks the right chopstick and starts eating.\n", n);
    sleep(2);
    printf("Philosopher %d finishes eating.\n", n);
    sem_post(&chopstick[n]);
    printf("Philosopher %d leaves left chopstick.\n", n);
    sem_post(&chopstick[(n+1)%5]);
    printf("Philosopher %d leaves the right chopstick.\n", n);
}
int main(){
    for(int i = 0; i<5; i++)
        sem_init(&chopstick[i], 0, 1);
    pthread_t tid[5]; //each thread represents one philosopher
    int philosopher_num[5];
    for(int i = 0; i<5; i++){
        philosopher_num[i] = i;
        pthread_create(&tid[i], NULL, philosopher, &philosopher_num[i]); //i -> denotes the current philosopher
    }
    for(int i = 0; i<5; i++)
        pthread_join(tid[i], NULL);
    return 0;
}