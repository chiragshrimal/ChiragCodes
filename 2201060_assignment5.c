#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<pthread.h>
#include<stdlib.h>
#include<ctype.h>

con

void* convert(void *argc){
    char *c= argc;
    if(islower(*c)){
        *c=toupper(*c);
    }else{
        if(isupper(*c)){
            *c=toupper(*c);
        }
    }

}

int main(){
    int n;
    printf("enter number of threads\n");
    scanf("%d",&n);
    char *input;
    char *output;
    printf("enter a string \n");
    
    pthread_t t[n];
    int m=sizeof(input)/n;gets(input);

    for(int i=0;i<m;i++){
    for(int i=0;i<n;i++){
        char c=input[i];
        if(pthread_create(&t[i],NULL,&convert,&c)){
            printf("error to create thread\n");
        }
    }
    }

    for(int i=0;i<m;i++){
    for(int i=0;i<n;i++){
        if(pthread_join(t[i],NULL)){
            printf("error to join thread\n");
        }
    }
    }

    printf(output);
    free(input);
    free(output);
    return 0;



}