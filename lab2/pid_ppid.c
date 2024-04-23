#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
	pid_t pid;
	pid = fork();
	if (pid < 0) { // Error occurred
		fprintf(stderr, "Fork failed\n");
		return 1;
	} else if (pid == 0) { // Child process
        	printf("Child PID: %d\n", getpid());
        	printf("Child's Parent PID: %d\n", getppid());
    	} else { // Parent process
        	printf("Parent PID: %d\n", getpid());
        	printf("Parent's Parent PID: %d\n", getppid());
    	}
	return 0;
}
