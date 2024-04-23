#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define READ_END 0
#define WRITE_END 1

int is_prime(int n){
	if(n<=1){
		return 0;
	}
	for(int i = 2; i<=n-1; i++){
		if(n%i==0){
			return 0;
		}
	}
	return 1;
}

int main(){
	int parent_to_child_pipe[2];
	int child_to_parent_pipe[2];
	if(pipe(parent_to_child_pipe) == -1 || pipe(child_to_parent_pipe) == -1){
		perror("Pipe creation failed\n");
		exit(EXIT_FAILURE);	
	}
	pid_t pid = fork();
	if(pid<0){
		perror("Fork failed\n");
		exit(EXIT_FAILURE);
	} else if(pid == 0){
		close(parent_to_child_pipe[WRITE_END]);
		close(child_to_parent_pipe[READ_END]);
		int num;
		read(parent_to_child_pipe[READ_END], &num, sizeof(int));
		close(parent_to_child_pipe[READ_END]);
		int result = is_prime(num);
		write(child_to_parent_pipe[WRITE_END], &result, sizeof(int));
		close(child_to_parent_pipe[WRITE_END]);
		exit(EXIT_SUCCESS);
	} else {
		close(parent_to_child_pipe[READ_END]);
		close(child_to_parent_pipe[WRITE_END]);
		int num;
		printf("Enter an integer: ");
		scanf("%d", &num);
		write(parent_to_child_pipe[WRITE_END], &num, sizeof(int));
		close(parent_to_child_pipe[WRITE_END]);
		int result;
		read(child_to_parent_pipe[READ_END], &result, sizeof(int));
		close(child_to_parent_pipe[READ_END]);
		if(result){
			printf("%d is a prime number", num);
		} else {
			printf("%d is not a prime number", num);
		}
	}
	return 0;
}
