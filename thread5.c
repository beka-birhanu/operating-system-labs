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
        for(int i = 0; i < 10; i++) {
            if(i % 2 == 1)  {
                printf("\nChild is printing %d\n", i);
                sleep(1);
            }
        }
    } else {
        // Parent process
        for(int i = 0; i < 10; i++) {
            if(i % 2 == 0)  {
                printf("\nParent is printing %d\n", i);
                sleep(1);
            }
        }
    }

    return 0;
}

