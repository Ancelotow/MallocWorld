/*
**  Filename : pnj.h
**
**  Made by : Owen ANCELOT & Elsa FIRMIN
**
**  Description : Header for 'pnj.c'
*/

#ifndef MALLOCWORLD_PNJ_H
#define MALLOCWORLD_PNJ_H

#include "player.h"
#include "../inventory/storage.h"

void stockPNJ(Player* player, Game* game);

void changeQuantityPNJ(Storage* storage, int id, int quantity, Game* game);

#endif //MALLOCWORLD_PNJ_H
