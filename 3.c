#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>

int main(){
    char ch;
    while((ch=getchar())!=EOF){
        if(islower(ch)){
            putchar(toupper(ch));
        }else{
            if(isupper(ch)){
                putchar(tolower(ch));
            }
        }
    }
    return 0;
}