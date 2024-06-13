#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>


int main() {
    pid_t pid = fork();

    if (pid < 0) {
        // Error handling
        perror("fork failed");
        return 1;
    } else if (pid == 0) {
        // Child process
        printf("\nChild process going to sleep\n");
        sleep(5); // Parent sleeps longer than the child
        printf("Child Process going to termination\n");
    } else {
        // Parent process
        printf("\nParent process going to sleep\n");
        sleep(1);

        printf("\nKilling child proccess\n");
        kill(pid, SIGQUIT);

        printf("\nChild killed, now terminating\n");
    }

    return 0;
}

