/*
**  Filename : position.h
**
**  Made by : Owen ANCELOT
**
**  Description : Header for 'position.c'. Manage the position of the player in the world (zone, row and column).
*/

#ifndef MALLOCWORLD_POSITION_H
#define MALLOCWORLD_POSITION_H

#include "world/zone.h"
#include "world/world.h"

typedef struct Position{
    int x;
    int y;
    int zone;
} Position;

Position* seekPlayer(World world);

void freePosition(Position* position);

#endif //MALLOCWORLD_POSITION_H
