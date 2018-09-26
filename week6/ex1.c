#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
	int fd[2];
	pipe(fd);
	char a[] = "hello world\n";
	char b[512];
	pipe(fd);
	write(fd[1], a, sizeof(a));
	read(fd[0], b, sizeof(b));
	close(fd[0]);
	close(fd[1]);
	printf("b: %s", b);
}
