#ifndef TAMAGOTCHI_H
#define TAMAGOTCHI_H

// Tamagotchi status constants
#define HUNGRY 0
#define SICK 1
#define DEAD 2
#define HAPPY 3
#define POWERED 4
#define GOD 5


//Config Game
#define CYCLE_HUNTER 5
#define CYCLE_HAPPINESS 5

// Tamagotchi actions
#define FEED 0
#define MEDICINE 1
#define PLAY 2

// Tamagotchi struct
typedef struct {
  int status;
  int hunger;
  int happiness;
  int cycle;
} Tamagotchi;

// Initialize a new Tamagotchi with default values
Tamagotchi* createTamagotchi(void);

// Perform an action on the Tamagotchi
void doAction(Tamagotchi* t, int action);

// Update the Tamagotchi's status based on its current values
void updateStatus(Tamagotchi* t);

// Print the current status of the Tamagotchi
void printStatus(Tamagotchi* t);

#endif
