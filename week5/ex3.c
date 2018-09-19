#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

#define MAX_COUNT 10
#define DEFAULT_INIT_NUM 0
// used to make some thread sleep/wakeup
int prod_id=0, cons_id=1;
// used to check if the thread is asleep or not
int prod_slp=0, cons_slp=1;

int number=DEFAULT_INIT_NUM;
int times=10000;

void sleep_(int n) {
	if (n == prod_id)
		prod_slp=1;
	else
		cons_slp=1;
}

void wakeup_(int n) {
	if (n == prod_id)
		prod_slp=0;
	else
		cons_slp=0;
}

void *producer(int* args[2]) {
	int* buf=args[0];
	int* count=args[1];
	printf("producer(): producer started\n");
	while(times) {
		if (*count==MAX_COUNT) {
			sleep_(prod_id);
			while(prod_slp);
		}
		while(*count==MAX_COUNT && prod_slp) {
			;		
		}
		printf("producer(): BUFFER WRITING...\n");
		*(buf + *count)=number;
		//number--;  // optional
		(*count)++;
		printf("producer(): BUFFER WRITING ENDED, count=%d\n", *count);
		if(*count>0) wakeup_(cons_id);
		//sleep(1);  //optional
	}
	pthread_exit(0);
}

void *consumer(int* args[2]) {
	int* buf=args[0];
	int* count=args[1];
	printf("consumer(): consumer started\n");
	while(times) {
		if (*count==0) {
			sleep_(cons_id);
			while(cons_slp);
		}
		printf("consumer(): BUFFER READING..\n");
		int i;
		printf("consumer(): OUTPUT - %d\n", *(buf + (*count - 1)));
		(*count)--;
		printf("consumer(): BUFFER READING ENDED, count=%d\n", *count);
		times--;
		if(*count<MAX_COUNT) wakeup_(prod_id);
		//sleep(1);  //optional
	}
	pthread_exit(0);
}

int main() {
	pthread_t prod, cons;
	int buf[MAX_COUNT];
	int count = 0;
	int* args[2];
	args[0]=&buf;
	args[1]=&count;
	printf("main(): Main started\n");
	if (pthread_create(&prod, NULL, producer, args) != 0) {
		perror("pthread_create() error\n");
		exit(1);
	}
	if (pthread_create(&cons, NULL, consumer, args) != 0) {
		perror("pthread_create() error\n");
		exit(1);
	}
	if (pthread_join(prod, NULL) != 0) {
		perror("pthread_create() error\n");
		exit(3);
	}
	if (pthread_join(cons, NULL) != 0) {
		perror("pthread_create() error\n");
		exit(3);
	}
	return 0;
}
