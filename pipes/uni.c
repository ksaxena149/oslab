#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#define MSG_SIZE 50

int main(){
	int fd[2];
	char msg[MSG_SIZE] = "Hello Child!";
	if(pipe(fd) == -1){
		perror("pipe"); // what does this do?
		exit(EXIT_FAILURE);
	}
	pid_t pid = fork();
	if(pid == -1){
		perror("fork");
		exit(EXIT_FAILURE);
	} else if(pid == 0){
		close(fd[1]); // close write end
		char bf[MSG_SIZE];
		read(fd[0], bf, sizeof(bf));
		printf("Child recieved message: %s\n", bf);
		close(fd[0]); // close read end
	} else {
		close(fd[0]); // close read end;
		write(fd[1], msg, strlen(msg)+1);
		close(fd[1]); // close write end;
	}

	return 0;
}
