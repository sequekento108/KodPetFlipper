#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include "social.h"

void readsocial(char *npc) {
  if (npc == NULL) {
    readfolder("enemies", 0);
    readfolder("friends", 0);
    readfolder("npc", 1);
  }
}

void readfolder(char *npc, int point) {
  DIR *folder;
  struct dirent *entry;
  int files = 0;
  folder = opendir(npc);
  if (folder == NULL) {
    perror("Unable to read directory");
  }

  while ((entry = readdir(folder))) {
    files++;
    switch (point) {
      // friend enemies
    case 0:
      if (!strstr(entry->d_name, ".")) {
        printf("%s %3d: %s\n", npc, files, entry->d_name);
      }
      break;
      // npc
    case 1:
      if (endswithfoonpc(entry->d_name) == 0) {
        printf("%s %3d: %s\n", npc, files, entry->d_name);
      }
      break;
    default:
      break;
    }
  }

  closedir(folder);
}

int endswithfoonpc(char *string) {
  string = strrchr(string, '.');
  if (string != NULL)
    return (strcmp(string, ".npcpet"));
  return -1;
}