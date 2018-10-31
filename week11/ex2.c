#include <stdio.h>

int main() {
  char buf[128];
  //setvbuf(stdout, buf, _IOLBF, 128);
  printf("H");
  sleep(1);
  printf("e");
  sleep(1);
  printf("l");
  sleep(1);
  printf("l");
  sleep(1);
  printf("o");
  sleep(1);
  printf("\n");
  return 0;
}
