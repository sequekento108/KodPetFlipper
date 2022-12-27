//
//  KodPet.c
//  KodPetFlipper
//
//  Created by KodamaDeveloper
//

#include "system/kodpet.h"
#include "system/savedata.c"
#include "system/savedata.h"
#include "system/social.h"
#include "system/social.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

// Flipper

//#include <furi.h>
//#include <gui/gui.h>
//#include <input/input.h>

// Initialize a new Tamagotchi with default values
Tamagotchi *createTamagotchi() {
  Tamagotchi *t = malloc(sizeof(Tamagotchi));
  t->status = HUNGRY;
  t->hunger = 50;
  t->happiness = 50;
  t->cycle = 0;
  t->care = 10;
  t->evolution = EGG;
  t->level = 0;
  t->intelligence = 1;
  t->strength = 1;
  t->agility = 1;
  t->critic = 1;
  t->defend = 1;
  t->life = 100;
  t->name = "KodPet";
  readsocial();
  if (savedataControl(t, "n"))
    return t;
  return t;
}

// Perform an action on the Tamagotchi
void doAction(Tamagotchi *t, int action) {
  int probcritic = rand() % 10;
  int probcritictmp = rand() % 10;
  switch (action) {
  case FEED:
    t->hunger += 13;
    if (t->life <= 99)
      t->life++;
    if (t->hunger > 100) {
      t->hunger = 100;
    }
    t->care--;
    printf("########  LAST ACTION: FEED\n");
    break;
  case MEDICINE:
    if (t->status == SICK) {
      t->status = HAPPY;
      t->hunger = 30;
      t->happiness = 30;
    }
    printf("########  LAST ACTION: MEDICINE\n");
    break;
  case PLAY:
    t->happiness += 12;
    if (t->happiness > 100) {
      t->happiness = 100;
      t->status = HAPPY;
    }
    t->care--;
    printf("########  LAST ACTION: PLAY\n");
    break;
  case CARE:
    t->care += 10;
    if (t->care > 30) {
      t->care = 30;
      t->happiness += HAPPY_FOR_CARE;
    }
    printf("########  LAST ACTION: CARE\n");
    break;
  case STUDY:
    t->intelligence++;
    t->hunger -= 30;
    printf("########  LAST ACTION: STUDY\n");
    break;
  case WORK:
    t->strength++;
    t->hunger -= 30;
    t->happiness -= 10;
    printf("########  LAST ACTION: WORK\n");
    break;
  case INVESTIGATE:
    t->agility++;
    t->hunger -= 38;
    printf("########  LAST ACTION: INVESTIGATE\n");
    break;
  case TRAIN:
    if (probcritic == probcritictmp)
      t->critic++;
    t->defend++;
    t->hunger -= 60;
    t->happiness++;
    printf("########  LAST ACTION: TRAIN\n");
    break;
  case TOOL:
    t->hunger--;
    t->happiness+= 8;
    t->life++;
    t->care--;
    printf("########  LAST ACTION: TRAIN\n");
    break;
  }

  if (t->status == DIRTY) {
    t->happiness--;
    t->life--;
  }
}

// Update the Tamagotchi's status based on its current values
void updateStatus(Tamagotchi *t) {
  if (t->hunger <= DEAD_HUNGER || t->happiness <= DEAD_HAPPINESS) {
    if (t->life >= 1) {
      t->life -= DAMAGE_FOR_CARE;
      t->strength--;
      if (t->life >= 1)
        return;
    }
    t->status = DEAD;
    return;
  } else if (t->hunger < 20 || t->happiness < 20) {
    t->status = SICK;
  } else if (t->happiness >= 70) {
    t->status = HAPPY;
  } else if (t->hunger < 50) {
    t->status = HUNGRY;
  } else {
    t->status = NORMAL;
  }

  if (t->care <= 0) {
    t->status = DIRTY;
    t->life--;
  }

  if (t->cycle >= CYCLE_EVOLUTION && t->evolution != QUANTUM) {
    t->evolution++;
    t->cycle = 0;
    t->level++;
    t->life = 100;
    printf("########  LEVEL UP!!!\n");
  }

  if (t->evolution == QUANTUM) {
    t->level++;
    printf("########  LEVEL UP!!!\n");
    t->life = 100;
  }
}

// Print the current status of the Tamagotchi
void printStatus(Tamagotchi *t) {
  int selectionoptionuser = 0;

  printf("########   %s\n", t->name);
  printf("Hunger: %d\n", t->hunger);
  printf("Happiness: %d\n", t->happiness);
  switch (t->status) {
  case HUNGRY:
    printf("Status: Hungry\n");
    break;
  case SICK:
    printf("Status: Sick\n");
    break;
  case HAPPY:
    printf("Status: HAPPY\n");
    break;
  case POWERED:
    printf("Status: POWERED\n");
    break;
  case GOD:
    printf("Status: GOD\n");
    break;
  case NORMAL:
    printf("Status: NORMAL\n");
    break;
  case DIRTY:
    printf("Status: DIRTY\n");
    break;
  case DEAD:
    printf("Status: Dead\n");
    break;
  }
  printf("Cycle: %i\n", t->cycle);
  printf("Evolution: %i\n", t->evolution);
  printf("Level: %i\n", t->level);
  printf("Intelligence: %i\n", t->intelligence);
  printf("Strength: %i\n", t->strength);
  printf("Agility: %i\n", t->agility);
  printf("Critic: %i\n", t->critic);
  printf("Defend: %i\n", t->defend);
  printf("Life: %i\n", t->life);
  printf("\n\n######## Select Option: \n 0. FEED. \n 1. MEDICINE \n 2. PLAY \n "
         "4. CARE \n 5. STUDY \n 6. WORK \n 7. INVESTIGATE \n 8. TRAIN \n 9. TOOL \n 98. Random Cycle Time \n 99. Close test \n");
  scanf("%d", &selectionoptionuser);

  int action = rand() % 3;
  switch (selectionoptionuser) {
  case 98:
    doAction(t, action);
    break;
  case 99:
    exit(0);
    break;
  default:
    doAction(t, selectionoptionuser);
    break;
  }

  printf("########   Selected: %i\n", selectionoptionuser);
}



int main() {
  srand(time(NULL));

  Tamagotchi *t = createTamagotchi();

  // Main game loop
  while (t->status != DEAD) {
    // Randomly choose an action for the Tamagotchi to perform

    // Decrease hunger and happiness over time
    t->hunger -= CYCLE_HUNTER;
    t->happiness -= CYCLE_HAPPINESS;

    // Update the Tamagotchi's status based on its current values
    updateStatus(t);

    // Print the current status of the Tamagotchi
    printStatus(t);
    t->cycle++;

    if (savedataControl(t, "s") == 0)
      printf("Saved progress");
  }

  // Game over
  printf("Game over!\n");

  return 0;
}
