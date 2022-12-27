#include <dirent.h>
#include <stdio.h>
#include <string.h>

void readsocial() {
  DIR *folder;
  struct dirent *entry;
  int files = 0;

  folder = opendir("friends");
  if (folder == NULL) {
    perror("Unable to read directory");
  }

  while ((entry = readdir(folder))) {
    files++;
    if(!strstr(entry->d_name, "."))
      printf("Friends %3d: %s\n", files, entry->d_name);
  }

  closedir(folder);

    folder = opendir("enemies");
  if (folder == NULL) {
    perror("Unable to read directory");
  }

  while ((entry = readdir(folder))) {
    files++;
    if(!strstr(entry->d_name, "."))
      printf("Enemies %3d: %s\n", files, entry->d_name);
  }

  closedir(folder);
}