//
//  KodPet.c
//  KodPetFlipper
//
//  Created by KodamaDeveloper
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "kodpet.h"

// Initialize a new Tamagotchi with default values
Tamagotchi* createTamagotchi() {
  Tamagotchi* t = malloc(sizeof(Tamagotchi));
  t->status = HUNGRY;
  t->hunger = 100;
  t->happiness = 100;
  t->cycle = 0;
  t->care = 10;
  t->evolution = EGG;
  return t;
}

// Perform an action on the Tamagotchi
void doAction(Tamagotchi* t, int action) {
printf("\n\n\n\n######## Cycle %i ###########\n", t->cycle);
printf("######## Evolution %i ###########\n", t->evolution);
  switch (action) {
    case FEED:
      t->hunger += 13;
      if (t->hunger > 100) {
        t->hunger = 100;
      }
      t->care--;
      printf("########  LAST ACTION: FEED\n");
      break;
    case MEDICINE:
      if (t->status == SICK) {
        t->status = HAPPY;
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
  }
  
}

// Update the Tamagotchi's status based on its current values
void updateStatus(Tamagotchi* t) {
  if (t->hunger <= DEAD_HUNGER || t->happiness <= DEAD_HAPPINESS) {
    t->status = DEAD;
  } else if (t->hunger < 20 || t->happiness < 20) {
    t->status = SICK;
  } else if(t->happiness >= 70){
    t->status = HAPPY;
  }
  else if(t->hunger < 50){
    t->status = HUNGRY;
  }else
  {
    t->status = NORMAL;
  }
  if(t->care <= 0){
    t->status = DIRTY;
  }
  
  if(t->cycle >= CYCLE_EVOLUTION && t->evolution != QUANTUM){
    t->evolution++;
    t->cycle = 0;
  }

}

// Print the current status of the Tamagotchi
void printStatus(Tamagotchi* t) {
  int selectionoptionuser = 0;

  printf("########\n");
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

  printf("######## Select Option: \n 0. FEED. \n 1. MEDICINE \n 2. PLAY \n 4. CARE \n 9. Random Cycle Time \n");
  scanf("%d",&selectionoptionuser);

  if(selectionoptionuser == 9){
      int action = rand() % 3;
      doAction(t, action);
  }else{
  doAction(t, selectionoptionuser);
  }
  printf("########   Selected: %i\n", selectionoptionuser);
}

int main() {
  srand(time(NULL));

  Tamagotchi* t = createTamagotchi();

  // Main game loop
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
    }

    // Game over
    printf("Game over!\n");

    return 0;
  }
