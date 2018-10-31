#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

int main() {
  int src = open("ex1.txt", O_RDONLY, 0);
  int dest = open("ex1.memcpy.txt", O_RDWR | O_CREAT, S_IWRITE | S_IREAD);
  struct stat st;
  fstat(src, &st);
  size_t fsize = (size_t) st.st_size;
  char *src_region = mmap((void*) NULL, fsize, PROT_READ, MAP_PRIVATE, src, 0);
  ftruncate(dest, fsize);
  char *dest_region = mmap((void*) NULL, fsize, PROT_READ | PROT_WRITE, MAP_SHARED, dest, 0);
  memcpy(dest_region, src_region, fsize);
  close(src);
  close(dest);
  return 0;
}
