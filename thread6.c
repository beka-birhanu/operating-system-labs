#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        // Error handling
        perror("fork failed");
        return 1;
    } else if (pid == 0) {
        // Child process
        printf("Child Process: PID = %d\n", getpid());
        exit(0); // Child exits
    } else {
        // Parent process
        sleep(10); // Parent sleeps longer than the child
        printf("Parent Process: PID = %d\n", getpid());
    }

    return 0;
}

