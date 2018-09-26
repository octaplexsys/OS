#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(void) {
        int fd[2];
        pid_t childpid;
        char a[] = "Hello, world!\n";
        char b[512];

        pipe(fd);
        
        if((childpid = fork()) == -1) {
                perror("fork error");
                exit(1);
        }

        if(childpid == 0) {
		close(fd[1]);
                read(fd[0], b, sizeof(b));
                printf("b: %s", b);
        }
        else {
                close(fd[0]);
                write(fd[1], a, sizeof(a));
                exit(0);
        }
}
