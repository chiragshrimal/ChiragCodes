#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
 int main(){
    char ch;
    int non_alphabetic=0;
    while((ch=getchar())!=EOF){
        if(!isalpha(ch)){
            non_alphabetic++;
        }
        putchar(ch);
    }
    fprintf(stderr,"final non_alphabetic character %d",non_alphabetic);
    return 0;
 }

