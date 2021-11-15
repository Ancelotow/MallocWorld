/*
**  Filename : respawn.h
**
**  Made by : Elsa FIRMIN
**
**  Description : Header for 'respawn.c'. Manage the respawn of monsters and resources with chained list
*/

#ifndef MALLOCWORLD_RESPAWN_H
#define MALLOCWORLD_RESPAWN_H

#include "../position.h"

typedef struct Respawn{
    int id;
    int roundLeft;
    Position* position;
    struct Respawn* child;
} Respawn;

Respawn* createRespawn(int id, Position* position);

void appendRespawn(Respawn* respawn, int id, Position* position);

void updateAllRespawn(Respawn* respawn);

void printRespawn(Respawn* respawn);

void freeRespawn(Respawn* respawn, int isRecursive);

#endif //MALLOCWORLD_RESPAWN_H
