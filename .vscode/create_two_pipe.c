#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
int main()
{
    int p1[2];
    int p2[2];
    if (pipe(p1) == -1 || pipe(p2) == -1)
    {
        printf("pipe not created\n");
        return 0;
    }
    int id1 = fork();
    if (id1 == -1)
    {
        printf("an error occured with fork\n");
        return 2;
    }
    if (id1 == 0)
    {
        close(p1[0]);
        close(p2[0]);
        close(p2[1]);
        int x;
        printf("enter a number\n");
        scanf("%d", &x);
        if (write(p1[1], &x, sizeof(int)) == -1)
        {
            printf("An error occured with writing in the pipe1\n");
            return 1;
        }
        close(p1[1]);
    }
    else
    {
        int id2 = fork();
        if (id2 == -1)
        {
            printf("an error occured with fork\n");
            return 3;
        }
        if (id2 == 0)
        {
            close(p1[1]);
            close(p2[0]);
            int y;
            if (read(p1[0], &y, sizeof(int)) == -1)
            {
                printf("An error occured with reading  in the pipe1\n");
                return 4;
            }
            y = y + 1;
            close(p1[0]);
            if (write(p2[1], &y, sizeof(int)) == -1)
            {
                printf("An error occured with reading  in the pipe2\n");
                return 5;
            }
            close(p2[1]);
        }
        else
        {
            close(p1[0]);
            close(p1[1]);
            close(p2[1]);
            int z;
            if (read(p2[0], &z, sizeof(int)) == -1)
            {
                printf("An error occured with reading in the pipe2\n");
                return 6;
            }
            z = z - 1;
            close(p2[0]);
            printf("%d", z);
        }
    }
    return 7;
}