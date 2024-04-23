#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>

void* thread_function(void* arg){
	printf("Inside the thread function\n");
	for(int i = 0; i<5; i++){
		printf("%d\n", i);
	}
}
int main(){
	pthread_t a_thread;
	pthread_create(&a_thread, NULL, thread_function, NULL);
	pthread_join(a_thread, NULL);
	printf("Inside main function\n");
	for(int i = 20; i<25; i++){
		printf("%d\n", i);
	}
}
