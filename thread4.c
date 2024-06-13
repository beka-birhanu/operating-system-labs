#include <stdio.h>
#include <unistd.h>


void task_for_child() {
    printf("\n Greetings, form child process\n");
}

void task_for_parent() {
    printf("\n Greetings, form parent process\n");
}


int main() {
    pid_t pid = fork();

    if (pid < 0) {
        // Error handling
        perror("fork failed");
        return 1;
    } else if (pid == 0) {
        // Child process
        task_for_child();
    } else {
        // Parent process
        task_for_parent();  
    }

    return 0;
}

