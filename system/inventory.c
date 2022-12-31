#include "inventory.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void openinventory(Tamagotchi *t) {
  printf("## INVENTORY \n");
  int countitem, selectionoptionuser = 0;
  for (int i = 0; i < 100; i++) {
    if (t->inventory[i] >= 1) {
      countitem++;
      printf("Value inventory pos %i with value %i \n", i, t->inventory[i]);
    }
  }
  printf("## Select pos item for use 9999 for back\n");
  scanf("%d", &selectionoptionuser);
  if (selectionoptionuser != 9999)
    useitem(t, selectionoptionuser);
    //TODO
}

void useitem(Tamagotchi *t, int pos) {

  switch (pos) {
  case POTION:
    /* code */
    break;
  case SUPERPOTION:
    /* code */
    break;
  case ULTRAPOTION:
    /* code */
    break;
  case ELIXIR_HAPPINESS:
    /* code */
    break;
  case ELIXIR_INTELLIGENCE:
    /* code */
    break;
  case ELIXIR_STRENGHT:
    /* code */
    break;
  case ELIXIR_AGILITY:
    /* code */
    break;
  case ELIXIR_CRITIC:
    /* code */
    break;
  case ELIXIR_DEFEND:
    /* code */
    break;

  default:
    break;
  }
}