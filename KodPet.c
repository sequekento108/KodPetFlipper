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
  t->hunger = 50;
  t->happiness = 50;
  t->cycle = 0;
  return t;
}

// Perform an action on the Tamagotchi
void doAction(Tamagotchi* t, int action) {
printf("\n\n\n\n######## Cycle %i ###########\n", t->cycle);
  switch (action) {
    case FEED:
      t->hunger += 10;
      if (t->hunger > 100) {
        t->hunger = 100;
      }
      printf("######## FEED\n");
      break;
    case MEDICINE:
      if (t->status == SICK) {
        t->status = HUNGRY;
      }
      printf("######## MEDICINE\n");
      break;
    case PLAY:
      t->happiness += 10;
      if (t->happiness > 100) {
        t->happiness = 100;
      }
      printf("######## PLAY\n");
      break;
  }
  
}

// Update the Tamagotchi's status based on its current values
void updateStatus(Tamagotchi* t) {
  if (t->hunger == 0 || t->happiness == 0) {
    t->status = DEAD;
  } else if (t->hunger < 20 || t->happiness < 20) {
    t->status = SICK;
  } else {
    t->status = HUNGRY;
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
    case DEAD:
      printf("Status: Dead\n");
      break;
  }

  printf("######## Select Option: \n 0. FEED. \n 1. MEDICINE \n 2. PLAY \n 9. Random Cycle Time \n");
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
      t->hunger -= 5;
      t->happiness -= 5;

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
