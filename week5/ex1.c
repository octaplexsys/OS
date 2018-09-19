#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

void *thread(int num) {
	printf("thread #'%d'\n", num);
	printf("hello world from thread #%d\n", num);
	pthread_exit(0);
}

int main() {
	int n, i;
	printf("Input number of threads:\n");
	scanf("%d", &n);
	pthread_t thid[n];
	printf("solution 1\n");
	for(i=1;i<=n;i++) {
		if (pthread_create(&thid[i-1], NULL, thread, i) != 0) {
			perror("pthread_create() error\n");
			exit(1);
		} else {
			printf("thread #%d created!\n", i);
		}
	}
	for(i=1;i<=n;i++) {
		if (pthread_join(thid[i-1], NULL) != 0) {
			perror("pthread_create() error\n");
			exit(3);
		}
	}
	
	printf("\nsolution 2\n");
	for(i=1;i<=n;i++) {
		if (pthread_create(&thid[i-1], NULL, thread, i) != 0) {
			perror("pthread_create() error\n");
			exit(1);
		} else {
			printf("thread #%d created!\n", i);
		}

		if (pthread_join(thid[i-1], NULL) != 0) {
			perror("pthread_create() error\n");
			exit(3);
		}
	}
	return 0;
}
