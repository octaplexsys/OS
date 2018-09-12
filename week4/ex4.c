#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	buffer = (char *)malloc(bufsize * sizeof(char));
	printf("Input q to quit the program\n");
	while(1) {
		char str[100];
		printf("> ");
		gets(str);
		if(!strcmp(str, "q")) 
			break;
		system(str);
	}
	return 0;
}
