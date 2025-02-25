#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include<sys/wait.h>
#include<errno.h>
int main()
{
    int fd[2];
    char buffer[100];
    // fd[0] for read
    // fd[1] for write
    if (pipe(fd) == -1)
    {
        printf("an error occured with opening the pipe\n");
        return 1;
    }
    int id = fork();// create child process
    if (id == -1)
    {
        printf("an error ocurred with fork\n");
        return 4;
    }
    if (id == 0)// for child process
    {
        close(fd[0]);
        char str[100];
        printf("enter string \n");
        gets(str);
        if (write(fd[1],str,50) == -1)
        { // it gives  us number of byte which we have to write
            printf("an error occured with writting in the pipe\n");
            return 3;
        }
        wait(NULL);
        close(fd[1]);
    }
    else
    {
        // for parent process
        close(fd[1]);
        if (read(fd[0], buffer, 100) == -1)
        {
            printf("an error occured with reading  in  the pipe\n");
            return 2;
        }
        close(fd[0]);
        printf("got from child process \n");
        printf(buffer);
    }
}
