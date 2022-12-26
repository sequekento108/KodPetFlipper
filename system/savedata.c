#include "./kodpet.h"
#include "savedata.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

void dataopen() {
  char ch, *fname;
  FILE *fpts, *fptt;

  printf("\n\n Decrypt a text file :\n");
  printf("--------------------------\n");

  fname = "memorycard/data.txt";

  fpts = fopen(fname, "w");
  if (fpts == NULL) {
    printf(" File does not exists or error in opening..!!");
    exit(7);
  }
  fptt = fopen("memorycard/temp.txt", "r");
  if (fptt == NULL) {
    printf(" File does not exists or error in opening..!!");
    fclose(fpts);
    exit(9);
  }
  while (1) {
    ch = fgetc(fptt);
    if (ch == EOF) {
      break;
    } else {
      ch = ch - 100;
      fputc(ch, fpts);
    }
  }
  printf(" The file %s desprotected successfully..!!\n\n", fname);
  fclose(fpts);
  fclose(fptt);
}
void dataclose() {
  char *fname, ch;
  FILE *fpts, *fptt;

  printf("\n\n Encrypt a text file :\n");
  printf("--------------------------\n");

  // scanf("%s",fname);
  fname = "memorycard/data.txt";

  fpts = fopen(fname, "r");
  if (fpts == NULL) {
    printf(" File does not exists or error in opening..!!");
    exit(1);
  }
  fptt = fopen("memorycard/temp.txt", "w");
  if (fptt == NULL) {
    printf(" Error in creation of file temp.txt ..!!");
    fclose(fpts);
    exit(2);
  }
  while (1) {
    ch = fgetc(fpts);
    if (ch == EOF) {
      break;
    } else {
      ch = ch + 100;
      fputc(ch, fptt);
    }
  }
  fclose(fpts);
  fclose(fptt);
  fpts = fopen(fname, "w");
  if (fpts == NULL) {
    printf(" File does not exists or error in opening..!!");
    exit(3);
  }
  fptt = fopen("memorycard/temp.txt", "r");
  if (fptt == NULL) {
    printf(" File does not exists or error in opening..!!");
    fclose(fpts);
    exit(4);
  }
  while (1) {
    ch = fgetc(fptt);
    if (ch == EOF) {
      break;
    } else {
      fputc(ch, fpts);
    }
  }
  printf(" File %s successfully protected ..!!\n\n", fname);
  fclose(fpts);
  fclose(fptt);
}

int parseInt(char *chars) {
  int sum = 0;
  int len = strlen(chars);
  for (int x = 0; x < len; x++) {
    int n = chars[len - (x + 1)] - '0';
    sum = sum + powInt(n, x);
  }
  return sum;
}

int powInt(int x, int y) {
  for (int i = 0; i < y; i++) {
    x *= 10;
  }
  return x;
}

int savedataControl(Tamagotchi *t, char *mode) {
  char *fileName = "memorycard/data.txt";
  char *normal = "n";
  char *save = "s";
  if (!access(fileName, F_OK) && mode == normal) {
    dataopen();
    printf("The File %s\t was Found\n", fileName);
    FILE *file_pointer;
    char buffer[64], c;

    file_pointer = fopen(fileName, "r");
    printf("----read a line progress----\n");
    fgets(buffer, 50, file_pointer);
    printf("%s\n", buffer);

    printf("----read and parse data progress----\n");
    file_pointer = fopen(fileName, "r"); // reset the pointer
    char str1[10], str2[10], str3[10], str4[10], str5[10], str6[10], str7[10],
        str8[10], str9[10], str10[10], str11[10], str12[10], str13[10];
    fscanf(file_pointer, "%s %s %s %s %s %s %s %s %s %s %s %s %s", str1, str2,
           str3, str4, str5, str6, str7, str8, str9, str10, str11, str12,
           str13);
    printf("Read Data |%s|\n", str1);
    printf("Read Data |%s|\n", str2);
    printf("Read Data |%s|\n", str3);
    printf("Read Data |%s|\n", str4);
    printf("Read Data |%s|\n", str5);
    printf("Read Data |%s|\n", str6);
    printf("Read Data |%s|\n", str7);
    printf("Read Data |%s|\n", str8);
    printf("Read Data |%s|\n", str9);
    printf("Read Data |%s|\n", str10);
    printf("Read Data |%s|\n", str11);
    printf("Read Data |%s|\n", str12);
    printf("Read Data |%s|\n", str13);

    printf("----read the entire file progress----\n");

    file_pointer = fopen(fileName, "r"); // reset the pointer
    while ((c = getc(file_pointer)) != EOF)
      printf("%c", c);

    t->status = parseInt(str1);
    t->hunger = parseInt(str2);
    t->happiness = parseInt(str3);
    t->cycle = parseInt(str4);
    t->care = parseInt(str5);
    t->evolution = parseInt(str6);
    t->level = parseInt(str7);
    t->intelligence = parseInt(str8);
    t->strength = parseInt(str9);
    t->agility = parseInt(str10);
    t->critic = parseInt(str11);
    t->defend = parseInt(str12);
    t->life = parseInt(str13);

    fclose(file_pointer);
    dataclose();
    return 0;
  } else {
    if (mode != save) {
      printf("The File %s\t not Found\n", fileName);
    } else {
      printf("Saved progress control");
    }

    int i;
    FILE *fptr;
    char fn[64];
    char str[64];
    snprintf(str, sizeof(str), "%i %i %i %i %i %i %i %i %i %i %i %i %i",
             t->status, t->hunger, t->happiness, t->cycle, t->care,
             t->evolution, t->level, t->intelligence, t->strength, t->agility,
             t->critic, t->defend, t->life);
    fptr = fopen(fileName, "w"); // "w" defines "writing mode"
    for (i = 0; str[i]; i++) {
      /* write to file using fputc() function */
      fputc(str[i], fptr);
    }
    fclose(fptr);
    dataclose();
    return 0;
  }

  if (!access(fileName, R_OK)) {
    printf("The File %s\t can be read\n", fileName);
  } else {
    printf("The File %s\t cannot be read\n", fileName);
  }

  if (!access(fileName, W_OK)) {
    printf("The File %s\t it can be Edited\n", fileName);
    return 1;
  } else {
    printf("The File %s\t it cannot be Edited\n", fileName);
  }

  if (!access(fileName, X_OK)) {
    printf("The File %s\t is an Executable\n", fileName);
  } else {
    printf("The File %s\t is not an Executable\n", fileName);
  }
}
