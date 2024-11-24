#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<time.h>
#include<signal.h>

void handler_sigstp(int sig){// yha sig like ctr+z hai
    printf("stop the program\n");
}

// program ko background m lejane ke liye ctr+z ka use krte hai
// program ko fground m le aane ke liye "fg" ka use krte hai
int main (){
    signal(SIGTSTP,&handler_sigstp);
    int x;
    printf("enter a number\n");
    scanf("%d",&x);
    printf("result is:%d=>%d",x,x*5);
}