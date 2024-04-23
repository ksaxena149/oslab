#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
	pid_t pid;
	pid = fork();
	if(pid<0){
		fprintf(stderr, "Fork failed\n");
		return 1;
	} else if(pid == 0){
		printf("Child process exiting immediately");
		exit(0);
	} else {
		sleep(5);
		printf("Parent process with pid: %d", getpid());
		
	}
	return 0;
}
