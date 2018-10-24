#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <string.h>
#include <sys/stat.h>

int main() {
  DIR* dirp = opendir(".");
  char files[100][100];
  int cnt_files=0, i, j;
  struct dirent* dp;
  int inodes[100], cnt_inodes=0;
  if (dirp == NULL) { return -1; }
  while ((dp = readdir(dirp)) != NULL) {
    strcpy(files[cnt_files++], dp->d_name);
  }
  for (i = 0; i < cnt_files; i++) {
    struct stat file_stat;
    stat(files[i], &file_stat);
    int inode = file_stat.st_ino;
    int exists = 0;
    for (j = 0; j < cnt_inodes; j++) {
      if (inode == inodes[j]) {
        exists = 1;
        break;
      }
    }
    if (!exists) {
      inodes[cnt_inodes++] = inode;
    }
  }
  for (i = 0; i < cnt_inodes; i++) {
    char eq_files[cnt_files][100];
    int cnt = 0;
    for (j = 0; j < cnt_files; j++) {
      struct stat file_stat;
      stat(files[j], &file_stat);
      int inode = file_stat.st_ino;
      if (inode == inodes[i]) {
        strcpy(eq_files[cnt++], files[j]);
      }
    }
    if (cnt >= 2) {
      printf("inode: %d\nfiles: ", inodes[i]);
      for (j = 0; j < cnt; j++) {
        printf("%s ", eq_files[j]);
      }
      printf("\n");
    }
  }
  return 0;
}
