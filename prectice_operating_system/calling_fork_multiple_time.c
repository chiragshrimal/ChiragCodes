#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){
    int id1=fork();
    int id2=fork();
    if(id1==0){
        if(id2==0){
            printf("sbse last wala chils / leaf node\n");
        }else{
            printf("hello from process x\n");
        }
    }else{
        if(id2==0){
            printf("hello from process y\n");
        }else{
            printf("hello from root pocess\n");
        }
    }
    while(wait(NULL)!=-1){// ydi bhut saare fork() call kiye ho toh  2 ya 2 se jyada 
        printf("waited for a child to finish\n");
    }

    return 0;
}