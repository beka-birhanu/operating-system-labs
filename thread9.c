#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        // Error handling
        perror("fork failed");
        return 1;
    } else if (pid == 0) {
        // Child process
        printf("Child: PID = %d, Parent PID = %d\n", getpid(), getppid());
        sleep(30); // Let the child run for some time
    } else {
        // Parent process
        printf("Parent: PID = %d, Child PID = %d\n", getpid(), pid);
        sleep(30); // Let the parent run for some time
    }

    return 0;
}
