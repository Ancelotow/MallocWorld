//
// Created by Admin on 19/10/2021.
//

#ifndef MALLOCWORLD_PLAYER_H
#define MALLOCWORLD_PLAYER_H

#include "inventory.h"

typedef struct Player{
    int currentHp;
    int maxHp;
    Inventory** inventory;
    int level;
    int xp;
    int xpNext;
} Player;

#endif //MALLOCWORLD_PLAYER_H
