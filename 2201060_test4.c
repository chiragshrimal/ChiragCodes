#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <ctype.h>
#include <string.h>

#define MAX_LENGTH 1000

char Input[MAX_LENGTH];
char Output[MAX_LENGTH];
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
int count =0;
pthread_mutex_t mutexcount = PTHREAD_MUTEX_INITIALIZER;

// Function to convert case
void* convertCase(void* arg) {
    int thread_id = *((int*)arg);
    int len = strlen(Input);
    
    for (int i = thread_id; i < len; i++) {
        pthread_mutex_lock(&mutex);
        char ch = Input[i];
        if (islower(ch))
            Output[i] = toupper(ch);
        else if (isupper(ch))
            Output[i] = tolower(ch);
        else
            Output[i] = ch; // Non-alphabetic characters remain unchanged
        pthread_mutex_unlock(&mutex);
    }

    return NULL;
}

int main() {
    int n;
    printf("Enter the sentence: ");
    fgets(Input, MAX_LENGTH, stdin);
    printf("Enter the number of threads: ");
    scanf("%d", &n);

    Input[strcspn(Input, "\n")] = 0;

    pthread_t threads[n];
    int thread_ids[n];

    int m=strlen(Input)/n;
   for(int i=0;i<m;i++){
    for (int i = 0; i < n; i++) {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, convertCase, &thread_ids[i]);
    }
   }

   
    for (int i = 0; i < n; i++) {
        pthread_join(threads[i], NULL);
    }

    
    printf("Converted string: %s\n", Output);

    return 0;
}

	
