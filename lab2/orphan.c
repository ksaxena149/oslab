#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
	pid_t pid = fork();
	if(pid<0){
		fprintf(stderr, "Fork failed\n");
		return 1;
	} else if (pid == 0){
		sleep(2);
		printf("Child process with PID=%d\n", getpid());
		printf("Child Process with PPID=%d\n", getppid());
	} else {
		printf("Parent process with PID:%d\n", getpid());
		printf("Parent Process exiting immediately.\n");
		exit(0);
	}
	return 0;
}

