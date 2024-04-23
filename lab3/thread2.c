#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *thread1_function(void *arg){
	FILE *fp;
	fp = fopen("Thread.txt", "w");
	if(fp==NULL){
		perror("Error creating file");
		pthread_exit(NULL);
	}
	fclose(fp);
	pthread_exit(NULL);
}

void *thread2_function(void *arg){
	FILE *fp;
	fp = fopen("Thread.txt", "a");
	if(fp==NULL){
		perror("Error opening file");
		pthread_exit(NULL);
	}
	fprintf(fp, "Hello from T2\n");
	fclose(fp);
	pthread_exit(NULL);
}

int main(){
	pthread_t thread1, thread2;
	pthread_create(&thread1, NULL, thread1_function, NULL);
	pthread_create(&thread2, NULL, thread2_function, NULL);
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	return 0;
}
