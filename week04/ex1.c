#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
	int n = 10;
	int pid = fork();
	switch(pid) {
		case -1:
		perror("fork");
		exit(1);
		case 0:
		printf("Hello from CHILD [%d %d]\n", getpid(), n);
		break;
		default:
		printf("Hello from PARENT [%d %d]\n", getpid(), n);	
	}
	return 0;
}
