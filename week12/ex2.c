#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#define BUFFER_SIZE 512

int main(int argc, char *argv[]) {

  char buf[BUFFER_SIZE];
  int sz = 1;
  char *input = malloc(BUFFER_SIZE * sizeof(char));
  if (input == NULL) {
    printf("ERROR_1!\n");
    return -1;
  }
  input[0] = '\0';
  while(fgets(buf, BUFFER_SIZE, stdin)) {
    sz += strlen(buf);
    input = realloc(input, sz);
    if (input == NULL) {
      printf("ERROR_2!\n");
      return -1;
    }
    strcat(input, buf);
  }

  char *flag;
  char *filename;
  if (argc == 3 && strcmp(argv[1], "-a") == 0) {
    flag = "a+";
    filename = argv[2];
  } else if (argc == 2){
    flag = "w";
    filename = argv[1];
  } else {
    printf("ERROR_3!\n");
    return -1;
  }
  int f = fopen(filename, flag);
  if (f < 0) {
    printf("ERROR_4!\n");
    return -1;
  }
  fprintf(f, "%s", input);
  close(f);

  printf("%s", input);
  return 0;
}
