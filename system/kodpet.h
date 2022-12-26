#ifndef TAMAGOTCHI_H
#define TAMAGOTCHI_H

// Tamagotchi status constants
#define HUNGRY 0
#define SICK 1
#define DEAD 2
#define HAPPY 3
#define POWERED 4
#define GOD 5
#define NORMAL 6
#define DIRTY 7

//SYSTEM OF EVOLUTIONS
#define EGG 0
#define BABY 1
#define NANO 2
#define MATURE 3
#define CYBER 4
#define QUANTUM 5

//PERSONALITY
#define WHITE 0
#define RED 1
#define BLACK 2
#define GREEN 3
#define GREY 4


//Config Game
#define CYCLE_HUNTER 5
#define CYCLE_HAPPINESS 5
#define HAPPY_FOR_CARE 5
#define DEAD_HUNGER -10
#define DEAD_HAPPINESS -30
#define CYCLE_EVOLUTION 10
#define DAMAGE_FOR_CARE 35

// Tamagotchi actions
#define FEED 0
#define MEDICINE 1
#define PLAY 2
#define RANDOM 3
#define CARE 4
#define STUDY 5

// Tamagotchi struct
typedef struct {
  int status; //1
  int hunger; //2
  int happiness; //3
  int cycle; //4
  int care; //5
  int evolution; //6
  int level; //7
  int intelligence;//8
  int strength; //9
  int agility; //10
  int critic; //11
  int defend; //12
  int life; //13
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
