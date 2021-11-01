//
// Created by Admin on 01/11/2021.
//

#ifndef MALLOCWORLD_POSITION_H
#define MALLOCWORLD_POSITION_H

#include "zone.h"
#include "world.h"

typedef struct Position{
    int x;
    int y;
    int zone;
} Position;

Position* seekPlayer(World world);

void freePosition(Position* position);

#endif //MALLOCWORLD_POSITION_H
