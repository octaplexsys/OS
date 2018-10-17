#include <stdio.h>
#include <stdlib.h>

struct result {
  int hit;
  int miss;
};

struct frame {
  int data;
  int age;
  int valid;
};

void decrease_ages(struct frame *table, int m) {
  int i;
  for (i = 0; i < m; i++) {
    if (table[i].age > 0)
      table[i].age = table[i].age >> 1;
  }
}

int get_frame_to_evict(struct frame *table, int m) {
  int i, min_age = table[0].age, index = 0;
  for (i = 0; i < m; i++) {
    if (table[i].age < min_age) {
      min_age = table[i].age;
    }
  }
  // choose a frame randomly among those with the least age.
  int ids[m], sz=0;
  for (i = 0; i < m; i++) {
    if (table[i].age == min_age) {
      ids[sz++] = i;
    }
  }
  index = ids[rand() % sz];
  return index;
}

struct result solve(int *array, int n, int m) {
  printf("%d\n", n);
  int max = 1 << 30, i, j;
  struct result res = {0, 0};
  struct frame table[m];
  for (i = 0; i < m; i++) {
    table[i].data = 0;
    table[i].age = -1;
    table[i].valid = 0;
  }
  for (i = 0; i < n; i++) {
    int found = 0, index;
    for (j = 0; j < m; j++) {
      if (table[j].valid == 1 && table[j].data == array[i]) {
        found = 1;
        index = j;
        break;
      }
    }
    if (found) {
      decrease_ages(table, m);
      table[index].age = max + table[index].age;
      res.hit++;
    } else {
      index = get_frame_to_evict(table, m);
      decrease_ages(table, m);
      table[index].valid = 1;
      table[index].data = array[i];
      table[index].age = max;
      res.miss++;
    }
  }
  return res;
}

int main() {
  srand(time(NULL));
  int m, n = 0;
  int array[2000];
  struct result res;

  FILE *fp;
  fp = fopen("input.txt", "r");
  int i;
  for(i = 0; fscanf(fp, "%d", &array[i]) != EOF; i++, n++);
  fclose(fp);

  m = 10;
  res = solve(array, n, m);
  printf("Number of page frames: %d Hit/Miss: %d/%d\n", m, res.hit, res.miss);

  m = 50;
  res = solve(array, n, m);
  printf("Number of page frames: %d Hit/Miss: %d/%d\n", m, res.hit, res.miss);

  m = 100;
  res = solve(array, n, m);
  printf("Number of page frames: %d Hit/Miss: %d/%d\n", m, res.hit, res.miss);

  return 0;
}
