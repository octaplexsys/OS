#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>

int main(void) {
        pid_t childpid;
        
        if((childpid = fork()) == -1) {
                perror("fork error");
                exit(1);
        }

        if(childpid == 0) {
		while(1) {
			printf("I'm alive\n");
			sleep(1);
		}
        }
        else {
		sleep(10);
                kill(childpid, SIGTERM);
                exit(0);
        }
}
