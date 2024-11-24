#include<stdio.h>
#include<stdlib.h>
int main (int argc,char*argv[]){
    for(int i=1;i<argc;i++){
        if(argv[i][0]!='-'){
            printf(argv[i]);
        }
    }
    return 0;
}