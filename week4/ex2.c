#include <stdio.h>
#include <stdlib.h>

int main() {
	fork();
	fork();
	sleep(1);
	fork();
	fork();
	sleep(1);
	fork();
	sleep(5);
	return 0;
}
