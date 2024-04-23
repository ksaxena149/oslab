#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <pthread.h>

void *thread_function(void *arg){
	int *x = arg;
	int *sum = malloc(sizeof(int));
	*sum = x[0] + x[1];
	printf("Sum calculated");
	pthread_exit((void *)sum);
}
int nums[] = {3, 5};
int main(){
	pthread_t a_thread;
	void* result;
	pthread_create(&a_thread, NULL, thread_function, (void *)nums);
	pthread_join(a_thread, &result);
	printf("Inside the main program\n");
	printf("The sum calculated is %d", *(int *)result);
	return 0;
}
