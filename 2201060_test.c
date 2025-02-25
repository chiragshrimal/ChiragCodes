#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>//system call ke liye
#include <signal.h>// signal bhejne ke liye 
#include <sys/types.h>
#include <sys/wait.h>
#include <setjmp.h>

jmp_buf env;

void alarm_handler(int signum) {
 printf("Calculation is taking too much time\n");
    longjmp(env, 1);
}

int is_prime(int n) {
    if (n <= 1) return 0;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) return 0;
    }
    return 1;
}

void find_primes(int x, int y) {
    for (int i = x; i <= y; ++i) {
        if (is_prime(i)) {
            printf("%d ", i);
        }
    }
    printf("\nAll the prime numbers printed\n");
}

int main() {
    int x, y, z;
    printf("Enter three numbers (x, y, z): ");
    scanf("%d %d %d", &x, &y, &z);

    pid_t pid = fork();

    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid == 0) { // Child process
        find_primes(x, y);
        exit(EXIT_SUCCESS);
    } else { // Parent process
        signal(SIGALRM, alarm_handler);
        if (setjmp(env) == 0) {
            alarm(z);
            wait(NULL);
            
        } else {
            kill(pid, SIGKILL);
        }
    }

    return 0;
}

