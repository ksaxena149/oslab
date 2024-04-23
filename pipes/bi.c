#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#define MSG_SIZE 50

int main(){
	int fd[2];
	char msg1[MSG_SIZE] = "Parent to child";
	char msg2[MSG_SIZE] = "Child to parent";
	if(pipe(fd)==-1){
		perror("pipe");
		exit(EXIT_FAILURE);
	}
	pid_t pid = fork();
	if(pid<0){
		perror("fork");
		exit(EXIT_FAILURE);
	} else if(pid == 0){
		close(fd[1]); // close write end because child process
		char bf[MSG_SIZE];
		read(fd[0], bf, sizeof(bf));
		printf("Child recieved message: %s", bf);
		write(fd[1], msg2, strlen(msg2)+1);
		close(fd[0]); // close read end because child process
	} else {
		close(fd[0]); // close read end because parent process
		write(fd[1], msg1, strlen(msg1)+1);
		char bf[MSG_SIZE];
		read(fd[0], bf, sizeof(bf));
		printf("Parent recieved message: %s", bf);
		close(fd[1]); // close write end because parent process
	}

	return 0;
}
