/*
**  Filename : fight.h
**
**  Made by : Owen ANCELOT
**
**  Description : Header for 'action.c'. It's used for fight's action
*/

#ifndef MALLOCWORLD_FIGHT_H
#define MALLOCWORLD_FIGHT_H

typedef struct Fight{
    Monster* monster;
    Inventory* weapon;
    Inventory* armor;
} Fight;

Fight* initFight(int id, Game* game);

Inventory* choiceWeapon(Player* player);

Inventory* choiceArmor(Player* player);

void startFight(int id, Game* game);

#endif //MALLOCWORLD_FIGHT_H
