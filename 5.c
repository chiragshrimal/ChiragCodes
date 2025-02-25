#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/types.h>
#include <errno.h>

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        fprintf(stderr, "Less arguments\n");
        exit(1);
    }

    int fd1 = open(argv[1], O_RDONLY);
    close(0);
    dup(fd1);

    int fd2 = open(argv[2], O_CREAT | O_WRONLY, 0644);
    close(1);
    dup(fd2);

    int p[2];
    pipe(p);

    if (fork() != 0)
    {
        if (fork() != 0)
        {
            close(p[1]);
            close(p[0]);
            wait(NULL);
            wait(NULL);
        }
        else
        {  
            //  sleep(5);
            close(p[1]);
            // close(0);
            
            // char buff[BUFSIZ];
            // read(p[0], buff,100);
            // fprintf(stderr,"hi: %s",buff);  
            
            // close(p[1]);
            // dup2(p[0],0);
          
            // // close(0);
            dup2(p[0],0);
            // sleep(2);
             execl("./convert", "convert", (char *)0);
        }
    }
    else
    {
         close(p[0]);
        
        dup2(p[1],1);
        // close(p[1]);
       execl("./count", "count", (char *)0);
        
    }
}