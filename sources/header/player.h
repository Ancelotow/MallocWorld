//
// Created by Admin on 19/10/2021.
//

#ifndef MALLOCWORLD_PLAYER_H
#define MALLOCWORLD_PLAYER_H

#include "inventory/inventory.h"
#include "inventory/stack.h"

typedef struct Player{
    int currentHp;
    int maxHp;
    Stack** inventory;
    int sizeInventory;
    int level;
    int xp;
    int xpNext;
} Player;

Player* createPlayer(int currentHp, int maxHp, Stack** inventory, int sizeInventory, int level, int xp, int xpNext);

Player* createPlayerLevel1();

void appendInventory(Player* player, Inventory* inventory);

void printPlayerDebug(Player player);

void printInventoryPlayer(Player player);

void freePlayer(Player* player);

#endif //MALLOCWORLD_PLAYER_H
