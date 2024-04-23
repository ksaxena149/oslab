#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 2

int shared_variable = 0;

void *increment_thread(void *arg){
	for(int i = 0; i<100000; i++){
		shared_variable++;
	}
	pthread_exit(NULL);
}

void *decrement_thread(void *arg){
	for(int i = 0; i<100000; i++){
		shared_variable--;
	}
	pthread_exit(NULL);
}

int main(){
	pthread_t threads[NUM_THREADS];
	int rc;
	rc = pthread_create(&threads[0], NULL, increment_thread, NULL);
	if(rc){
		printf("Error: unable to create increment thread, %d\n", rc);
		exit(EXIT_FAILURE);
	}
	rc = pthread_create(&threads[1], NULL, decrement_thread, NULL);
	if(rc){
		printf("Error: unable to create decrement thread, %d\n", rc);
		exit(EXIT_FAILURE);
	}
	for(int i = 0; i<NUM_THREADS; i++){
		if(pthread_join(threads[i], NULL)){
			printf("Error: unable to join thread %d\n", i);
			exit(EXIT_FAILURE);
		}
	}
	printf("Final value of shared variable: %d\n", shared_variable);
	return 0;
}
