#include<stdio.h>
#include<fcntl.h>
int main (){
    //open
    int fd;
    fd=open("example.txt",O_RDONLY|O_CREAT,0644);
    if(fd==-1){
        perror("error opening file");
        return 1;
    }
    printf("file opening successfully with discripter %d",fd);
    close(fd);

    // create
    int fd1;
    fd1=creat("example.txt",0644);
    if(fd1==-1){
        perror("error creating file ");
        return 1;
    }
    printf("file creating successfully with file discripter %d",fd1);


    // dup()
    int fd2 = open("example.txt", O_RDONLY);

    if (fd2 == -1) {
        perror("Error opening file");
        return 1;
    }

    // Duplicate the file descriptor
    int new_fd = dup(fd2);

    printf("Original file descriptor: %d\n", fd2);
    printf("Duplicated file descriptor: %d\n", new_fd);

    // Add your code here for reading or any other operations

    // Close the file descriptors
    close(fd2);
    close(new_fd);

    // dup2
    int fd3, new_fd1;

    // Open a file for reading
    fd3 = open("example.txt", O_RDONLY);

    if (fd3 == -1) {
        perror("Error opening file");
        return 1;
    }

    // Duplicate the file descriptor with a specific value
    new_fd1 = dup2(fd3, 10);  // 10 is the desired file descriptor

    printf("Original file descriptor: %d\n", fd3);
    printf("Duplicated file descriptor: %d\n", new_fd1);

    // Add your code here for reading or any other operations

    // Close the file descriptors
    close(fd3);
    close(new_fd1);


    //pipe
    int pipefd[2];
    if(pipe(pipefd)==-1){
        perror("pipe creation failed ");
        return 1;
    }
    printf("pipe created succesfully with read %d , for write %d",pipefd[0],pipefd[1]);

    close(pipefd[0]);
    close(pipefd[1]);

    //read()

    int fd4;
    char buffer[100];
    
    fd4=open("example.txt",O_RDONLY);
    if(fd4==-1){
        perror("error opening file");
        return 1;

    }
    printf("file opening succesfully with file discripter %d",fd4);

    size_t byteread=read(fd4,buffer,sizeof(buffer));
    if(byteread==-1){
        perror("erroe reading from file");
        return 1;

    }
    printf("read %zd byte from file and %s",byteread,buffer);
    close(fd4);

    //write()
    int fd5;
    char buffer[]="hello , i am chirag";
    
    fd5=open("example.txt",O_WRONLY| O_CREAT,0644);
    if(fd5==-1){
        perror("error opening file ");
        return 1;
    }
    size_t bytewrite=write(fd5,buffer,size(buffer)-1);
    if(bytewrite==-1){
        perror("error writing to file");
        close(fd5);
        return 1;
    }
    printf("wrote %zd in the file",bytewrite);
    close(fd5); 
    return 0;

}