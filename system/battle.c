

int whowinbattlegotchi(Tamagotchi *player0, Tamagotchi *player1) {
  int life0, life1, rintelligenceinbase0, rstrengthinbase0, ragilityinbase0,
      rdefendinbase0, rlifeinbase0, attack;

  life0 = player0->life * player0->evolution;
  life1 = player1->life * player1->evolution;
  rlifeinbase0 = life0 - life1;
  rintelligenceinbase0 = player0->intelligence - player1->intelligence;
  rstrengthinbase0 =
      ((player0->strength + ((player0->strength / 2)) * player0->critic)) -
      ((player1->strength + ((player1->strength / 2)) * player1->critic));
  ragilityinbase0 = player0->agility - player1->agility;
  rdefendinbase0 = player0->defend - player1->defend;
  attack = rlifeinbase0 + rstrengthinbase0 + ragilityinbase0 + rdefendinbase0 +
           rlifeinbase0;
  if (attack <= 0)
    return 1;
  else
    return 0;
}