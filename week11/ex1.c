#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

int main() {
  int f = open("ex1.txt", O_RDWR, 0);
  char *str = "This is a nice day";
  int fsize = strlen(str);
  ftruncate(f, fsize);
  char *region = mmap((void*) NULL, fsize, PROT_READ | PROT_WRITE | PROT_EXEC, MAP_SHARED, f, 0);
  strcpy(region, "This is a nice day");
  close(f);
  return 0;
}
