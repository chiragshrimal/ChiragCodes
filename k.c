#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void child_input(int write_pipe) {
    close(write_pipe);

    char input;
    while (1) {
        printf("Enter a character for Child 1 (or 'Ctrl + D' to exit): ");
        if (scanf(" %c", &input) == EOF) {
            close(STDOUT_FILENO);  // Close standard output to signal child_processing to exit
            exit(0);
        }

        write(STDOUT_FILENO, &input, sizeof(char));
    }
}

void child_processing(int read_pipe, int write_pipe) {
    close(read_pipe);

    char input;
    while (1) {
        if (read(STDIN_FILENO, &input, sizeof(char)) == 0) {
            // End of file received, terminate the process
            close(write_pipe);
            exit(0);
        }

        input++;

        write(write_pipe, &input, sizeof(char));
    }
}

void parent(int read_pipe) {
    close(read_pipe);

    char input;
    while (1) {
        if (read(STDIN_FILENO, &input, sizeof(char)) == 0) {
            // End of file received, terminate child processes
            break;
        }

        printf("Parent received: %c\n", input - 1);
    }

    // Wait for both child processes to terminate
    wait(NULL);
    wait(NULL);

    printf("Child processes terminated\n");
    exit(EXIT_SUCCESS);
}

int main() {
    int pipe1[2], pipe2[2];
    pid_t pid1, pid2;

    if (pipe(pipe1) == -1 || pipe(pipe2) == -1) {
        perror("Pipe creation failed");
        exit(EXIT_FAILURE);
    }

    pid1 = fork();

    if (pid1 == -1) {
        perror("First fork failed");
        exit(EXIT_FAILURE);
    } else if (pid1 == 0) {
        // Child 1
        close(pipe1[0]);  // Close read end
        close(pipe2[0]);  // Close read end
        close(pipe2[1]);  // Close write end
        child_input(pipe1[1]);
    } else {
        pid2 = fork();

        if (pid2 == -1) {
            perror("Second fork failed");
            exit(EXIT_FAILURE);
        } else if (pid2 == 0) {
            // Child 2
            close(pipe1[1]);  // Close write end
            close(pipe2[0]);  // Close read end
            child_processing(pipe1[0], pipe2[1]);
        } else {
            // Parent
            close(pipe1[0]);  // Close read end
            close(pipe1[1]);  // Close write end
            close(pipe2[1]);  // Close write end

            parent(pipe2[0]);

            // Wait for both child processes to terminate
            wait(NULL);
            wait(NULL);

            printf("Parent process exiting\n");
        }
    }

    return 0;
}