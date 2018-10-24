#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFER_SIZE 64
#define BG_JOB "&"
#define QUIT "q"
#define NEW_CMD "> "

int main() {
	printf("Input q to quit the program\n");
	while(1) {
		char str[BUFFER_SIZE];
		char str2[BUFFER_SIZE];
		char cmd[BUFFER_SIZE];
		char *pointer;
		printf(NEW_CMD);
		fgets(str, BUFFER_SIZE, stdin);
		if(!strcmp(str, QUIT)) 
			break;
		strcpy(str2, str);
		pointer = strtok(str, " ");
		if(pointer != NULL){
		    strcpy(cmd, pointer);
		}
		if(strchr(str2, BG_JOB)) {
			int pid = fork();
			if(!pid) {
				if (execvp(cmd, str) < 0) {     
					printf("*** ERROR: exec failed\n");
					exit(1);
			    	}
			}
		}
		else {
			system(str2);
		}
	}
	return 0;
}
