#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void) {
        pid_t childpid2, childpid1;
	int fd[2];

	pipe(fd);
        
        if((childpid1 = fork()) == -1) {
                perror("fork error");
		exit(1);
        }

        if(childpid1 == 0) {
		close(fd[1]);
                read(fd[0], &childpid2, sizeof(childpid2));
		printf("\nChild#1 has read from pipe. pid=%d\n", childpid2);
		sleep(2);
		kill(childpid2, SIGSTOP);
		printf("\nChild#1 has sent a signal to child#2\n");
                exit(0);
        }
        else {
		if((childpid2 = fork()) == -1) {
		        perror("fork error");
		        exit(1);
		}

		if(childpid2 == 0) {
			while(1) {
				printf("\nChild#2 is running...\n");
				sleep(1);
			}
			exit(0);
		}
		else {
			int status;
                	close(fd[0]);
                	write(fd[1], &childpid2, sizeof(childpid2));
			printf("\nParent has written to pipe. pid=%d\n", childpid2);
			waitpid(childpid2, &status, WUNTRACED);
			printf("\nSIGSTOP number: %d\n", SIGSTOP);
			printf("\nChild#2 has finished with status %d\n", WSTOPSIG(status));
		        exit(0);
		}
        }
}
