#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>
#include<pthread.h>

// we want to get value from thread function execution to the main function
void* roll_dice(){
    int value=(rand()%6)+1;
    printf("%d\n",value);
    int* result=malloc(sizeof(int));
    *result=value;
    return (void*)result;
    //pthread_exit((void*)result);// we can use this function rather than return 
}

int main(int argc,char*argv[]){
    pthread_t th;
    int *res;
    srand(time(NULL));// every time alg alg number generate kar paye rand() function
    if(pthread_create(&th,NULL,&roll_dice,NULL)!=0){
        printf("error to create new thread\n");
        return 1;
    }
    //return 0; not good to return here
    // sare thread ko khtm or thread se kuch print nhi hoga 

    if(pthread_join(th,(void**)&res)!=0){// store the value in res return by the function                             
        return 2;
    }
    printf("%d",*res);
    free(res);                                                                                                                                                                                                             
    return 0;
}
