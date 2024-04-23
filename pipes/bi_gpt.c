#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MSG_SIZE 20

int main() {
    int fd[2]; // File descriptors for the pipe
    char msg1[MSG_SIZE] = "Message 1"; // Message from parent to child
    char msg2[MSG_SIZE] = "Message 2"; // Message from child to parent

    // Create the pipe
    if (pipe(fd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    // Create a child process
    pid_t pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid == 0) { // Child process
        close(fd[0]); // Close read end of the pipe

        // Write message to the pipe
        if (write(fd[1], msg2, strlen(msg2)+1) == -1) {
            perror("write");
            exit(EXIT_FAILURE);
        }

        close(fd[1]); // Close write end of the pipe
    } else { // Parent process
        close(fd[1]); // Close write end of the pipe

        char buf[MSG_SIZE];

        // Wait for child to finish writing
        wait(NULL);

        // Read message from the pipe
        if (read(fd[0], buf, sizeof(buf)) == -1) {
            perror("read");
            exit(EXIT_FAILURE);
        }
        printf("Parent received message from child: %s\n", buf);

        // Write message to the pipe
        if (write(fd[1], msg1, strlen(msg1)+1) == -1) {
            perror("write");
            exit(EXIT_FAILURE);
        }

        close(fd[0]); // Close read end of the pipe
    }

    return 0;
}

