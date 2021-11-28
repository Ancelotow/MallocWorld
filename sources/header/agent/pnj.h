/*
**  Filename : pnj.h
**
**  Made by : Elsa FIRMIN
**
**  Description : Header for 'pnj.c'. Manage action with PNJ (storage, repair, craft)
*/

#ifndef MALLOCWORLD_PNJ_H
#define MALLOCWORLD_PNJ_H

void interactionWithPnj(Game* game);

int actionPNJ(char action, Game* game);

void repairPlayerInventory(Player* player);

void stockStorage(Game* game);

void retrieveStorage(Game* game);

#endif //MALLOCWORLD_PNJ_H
