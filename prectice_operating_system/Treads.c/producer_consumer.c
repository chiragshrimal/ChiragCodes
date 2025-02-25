#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>
#include <semaphore.h>
// manage shared memory access
// checking for if buffer is full
//  checking  for if buffer is empty

int buffer[10];
int count = 0;
pthread_mutex_t mutexcount;
sem_t semFull;
sem_t semEmpty;

void *producer()
{
    while (1)
    {
        // produce
        int x = rand() % 100;
        sleep(1);
        sem_wait(&semEmpty);// because buffe ka size maximum 10 hain
        pthread_mutex_lock(&mutexcount);
        buffer[count] = x;
        count++;
        printf("put data\n");
        pthread_mutex_unlock(&mutexcount);
        sem_post(&semFull);
    }
}

void *consumer()
{
    while (1)
    {
        int y = -1;
        sem_wait(&semFull);
        pthread_mutex_lock(&mutexcount);
            y = buffer[count - 1];
            count--;
        pthread_mutex_unlock(&mutexcount);
        sem_post(&semEmpty);
        printf("GOT %d\n", y);
        sleep(1);
    }
}

int main(int argc, char *argv[])
{
    srand(time(NULL));
    pthread_mutex_init(&mutexcount, NULL);
    sem_init(&semFull, 0, 0);
    sem_init(&semEmpty, 0, 10);
    pthread_t t[2];
    for (int i = 0; i < 2; i++)
    {
        if (i % 2 == 0)
        {
            if (pthread_create(&t[i], NULL, &producer, NULL) != 0)
            {
                printf("error to create thread\n");
            }
        }
        else
        {
            if (pthread_create(&t[i], NULL, &consumer, NULL) != 0)
            {
                printf("error to create thread\n");
            }
        }
    }
    pthread_mutex_destroy(&mutexcount);
    sem_destroy(&semFull);
    sem_destroy(&semEmpty);
    for (int i = 0; i < 2; i++)
    {
        if (pthread_join(t[i], NULL) != 0)
        {
            printf("error to join thread\n");
        }
    }
}