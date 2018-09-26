#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>

void sgkill(int signum) {
printf("\nSIGKILL caught\n");
}

void sgstop(int signum) {
printf("\nSIGSTOP caught\n");
}

void sgusr1(int signum) {
printf("\nSIGUSR1 caught\n");
}

int main(void) {
signal(SIGKILL, sgkill);
signal(SIGSTOP, sgstop);
signal(SIGUSR1, sgusr1);
printf("\nThe program started in background...\n");
printf("My pid: %d\n", (int)getpid());
while(1) sleep(1);
}
