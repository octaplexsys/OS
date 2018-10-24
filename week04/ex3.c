#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	printf("Input q to quit the program\n");
	while(1) {
		char str[100];
		printf("> ");
		scanf("%s", str);
		if(!strcmp(str, "q")) 
			break;
		system(str);
	}
	return 0;
}
