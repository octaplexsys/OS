#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N_SIZE 100
#define M_SIZE 100

int main() {
  int c[N_SIZE][M_SIZE], r[N_SIZE][M_SIZE];
  int e[M_SIZE], a[M_SIZE], mark[N_SIZE];
  int n = 0, m = 0, marked = 0;

  // find sizes n and m
  char buffer[10000];
  char *buffer2;
  FILE *file = fopen("input.txt", "r");
  if (file < 0) {
    printf("Error1\n");
    exit(1);
  }
  while(1) {
    if (!fgets(buffer, sizeof buffer, file)) break;
    buffer2 = buffer;
    int i = 0;
    while(1) {
      if (*buffer2 == '\n') {
        if (i != 0) {
          n++;
          if (m == 0) {
            m = i;
          } else if (m != i) {
            printf("Error2\n");
            exit(2);
          }
        }
        break;
      }
      int value = strtol(buffer2, &buffer2, 10);
      i++;
    }
  }
  if (n % 2 != 0) {
    printf("Error3\n");
    exit(3);
  } else {
    n = (n - 2) / 2;
  }
  fclose(file);

  // read numbers
  file = fopen("input.txt", "r");
  int i, j;
  for (i = 0; i < m; i++) {
    fscanf(file, "%d", &e[i]);
  }
  for (i = 0; i < m; i++) {
    fscanf(file, "%d", &a[i]);
  }
  for (i = 0; i < n; i++) {
    for (j = 0;j < m; j++) {
      fscanf(file, "%d", &c[i][j]);
    }
    mark[i] = 0;
  }
  for (i = 0; i < n; i++) {
    for (j = 0;j < m; j++) {
      fscanf(file, "%d", &r[i][j]);
    }
  }
  fclose(file);

  //run deadlock detection algorithm
  int found = 0;
  do {
    found = 0;
    int i, j;
    for (i = 0; i < n; i++) {
      if (mark[i]) continue;
      int less_equal = 1;
      for (j = 0; j < m; j++) {
        if (r[i][j] > a[j]) {
          less_equal = 0; break;
        }
      }
      if (less_equal) {
        found = 1;
        mark[i] = 1;
        marked++;
        for (j = 0; j < m; j++) {
          a[j] += c[i][j];
        }
      }
    }
  } while(found);
  file = fopen("output.txt", "w");
  if (marked == n) {
    fprintf(file, "No deadlocks!\n");
  } else {
    fprintf(file, "Some deadlocks found!\n");
    fprintf(file, "Processes numbers (from 0):");
    int i;
    for (i = 0; i < n; i++) {
      if (!mark[i]) fprintf(file, " %d", i);
    }
    fprintf(file, "\n");
  }
  fclose(file);
  return 0;
}
