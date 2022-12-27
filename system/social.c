#include <dirent.h>
#include <stdio.h>
#include <string.h>

void readsocial(char *npc) {
  if (npc == NULL) {
    readfolder("enemies");
    readfolder("friends");
    readfolder("npc");
  }
}

void readfolder(char* npc) {
  DIR *folder;
  struct dirent *entry;
  int files = 0;
  folder = opendir(npc);
  if (folder == NULL) {
    perror("Unable to read directory");
  }

  while ((entry = readdir(folder))) {
    files++;
    if (!strstr(entry->d_name, ".")){
      printf("%s %3d: %s\n", npc, files, entry->d_name);
    }
  }

  closedir(folder);
}