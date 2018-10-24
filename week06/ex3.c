#include <stdio.h>
#include <signal.h>

void out(int signum) {
printf("\nSIGINT caught, You have entered Ctrl+C!\n");
}

int main(void) {
printf("The program started. Press Ctrl+C\n");
signal(SIGINT, out);
while(1);
}
